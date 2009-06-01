#include <sys/procmgr.h>
#include <sys/netmgr.h>
#include <sys/dispatch.h>
#include <sys/iomsg.h>
#include <sys/rsrcdbmgr.h>
#include <sys/slog.h>
#include <sys/slogcodes.h>
#include <unistd.h>
#include <err.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

extern char * __progname;

void fail(int , const char *)__attribute__((__noreturn__));
int std_open(resmgr_context_t *, io_open_t *, RESMGR_HANDLE_T *, void *);
int std_stat(resmgr_context_t *, io_stat_t *, void *);


dispatch_t	*dpp;
dev_t		devno;
int		done;

resmgr_connect_funcs_t std_connect_funcs = {
	.nfuncs =	_RESMGR_IO_NFUNCS,
	.open =		std_open,
};

resmgr_io_funcs_t std_io_funcs = {
	.nfuncs =	_RESMGR_IO_NFUNCS,
	.stat =		std_stat,
};

struct pinfo {
	const char	*path;
	int		idx;
	int		path_id;
} pinfo[3] = {
	{
		.path = "/dev/stdin",
		.idx = STDIN_FILENO
	},
	{
		.path = "/dev/stdout",
		.idx = STDOUT_FILENO
	},
	{
		.path = "/dev/stderr",
		.idx = STDERR_FILENO
	},
};

void
handler(int signo)
{
	done = 1;
}

void
fail(int stage, const char *msg)
{
	switch (stage) {
	case -1:
	case 5:
		resmgr_detach(dpp, pinfo[2].path_id, _RESMGR_DETACH_ALL);
		/* FALLTHROUGH */
	case 4:
		resmgr_detach(dpp, pinfo[1].path_id, _RESMGR_DETACH_ALL);
		/* FALLTHROUGH */
	case 3:
		resmgr_detach(dpp, pinfo[0].path_id, _RESMGR_DETACH_ALL);
		/* FALLTHROUGH */
	case 2:
		dispatch_destroy(dpp);
		/* FALLTHROUGH */
	case 1:
		rsrcdbmgr_devno_detach(devno, 0);
		/* FALLTHROUGH */
	case 0:
		/* FALLTHROUGH */
	default:
		break;
	}

	if (msg != NULL)
		err(EXIT_FAILURE, msg);
	exit(EXIT_SUCCESS);
}

int
main(int argc, char **argv)
{
	int			init, i;
	dispatch_context_t	*ctp;
	struct pinfo		*pp;

	init = 0;

	signal(SIGTERM, handler);

	if ((devno = rsrcdbmgr_devno_attach(_MAJOR_DEV, -1, 0)) == -1) {
		fail(init, "rsrcdbmgr_devno_attach");
	}
	init++;

	if ((dpp = dispatch_create()) == NULL)
		fail(init, "dispatch_create");
	init++;

	for (i = 0; i < sizeof(pinfo) / sizeof(pinfo[0]); i++) {
		pp = &pinfo[i];
		if ((pp->path_id = resmgr_attach(dpp, NULL, pp->path,
		    _FTYPE_ANY, 0, &std_connect_funcs, &std_io_funcs,
		    pp)) == -1) {
			fail(init, "resmgr_attach");
		}
		init++;
	}

	if ((ctp = dispatch_context_alloc(dpp)) == NULL)
		fail(init, "dispatch_context_alloc");

	procmgr_daemon(0, 0);

	do {
		if ((ctp = dispatch_block(ctp)) == NULL) {
			slogf(_SLOGC_CHAR, _SLOG_ERROR,
			    "%s: dispatch_block failed", __progname);
			break;
		}

		dispatch_handler(ctp);
	} while (!done);

	fail(-1, NULL);
}

int
std_open(resmgr_context_t *ctp, io_open_t *msg, RESMGR_HANDLE_T *hdl, void *extra)
{
	struct _io_connect_link_reply	*linkp;
	struct _server_info		*info;
	io_dup_t			*new;
	unsigned			eflag;
	struct pinfo			*pp;

	linkp = (void *)msg;
	info = (void *)(linkp + 1);
	new = (void *)(info + 1);

	pp = hdl;

	if ((msg->connect.ioflag & (_IO_FLAG_RD | _IO_FLAG_WR)) == 0) {
		if (resmgr_open_bind(ctp, pp, 0) == -1) {
			return errno;
		}
		return EOK;
	}

	if (ctp->info.nd != ND_LOCAL_NODE) {
		return ENOREMOTE;
	}

	eflag = msg->connect.eflag;

	if (ConnectServerInfo(ctp->info.pid, pp->idx, info) != pp->idx)
		return EBADF;

	memset(new, 0x00, sizeof(*new));
	new->i.type = _IO_DUP;
	new->i.combine_len = sizeof(new->i);
	new->i.info.nd = netmgr_remote_nd(info->nd, ND_LOCAL_NODE);
	new->i.info.pid = ctp->info.pid;
	new->i.info.chid = info->chid;
	new->i.info.scoid = info->scoid;
	new->i.info.coid = pp->idx;

	_IO_SET_CONNECT_RET(ctp, _IO_CONNECT_RET_MSG);
	memset(linkp, 0x00, sizeof *linkp);
	linkp->eflag = eflag;
	linkp->path_len = sizeof *new;
	return _RESMGR_PTR(ctp, msg, sizeof *linkp + sizeof *info + sizeof *new);
}

int
std_stat(resmgr_context_t *ctp, io_stat_t *msg, void *ocb)
{
	struct pinfo	*pp;

	pp = ocb;

	memset(&msg->o, 0x00, sizeof msg->o);
	msg->o.st_ino = pp->idx;
	msg->o.st_size = 0;
	msg->o.st_ctime = msg->o.st_mtime = msg->o.st_atime = time(0);
	msg->o.st_mode = 0666 | S_IFCHR;
	msg->o.st_nlink = 1;
	msg->o.st_dev = (ctp->info.srcnd << ND_NODE_BITS) |
	    (devno & ND_NODE_MASK);
	msg->o.st_rdev = msg->o.st_dev;
	return _RESMGR_PTR(ctp, &msg->o, sizeof msg->o);
}
