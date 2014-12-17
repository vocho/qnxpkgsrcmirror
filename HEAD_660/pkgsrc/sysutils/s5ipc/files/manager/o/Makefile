all: s5ipc

OBJS= ipc.o ipc_main.o shm_mgr.o
s5ipc: ${OBJS}
	cc -o $@ ${OBJS}


ipc.o: ../ipc.c
	cc -c  -I ../inc -I ../../lib/public -o $@ $<

ipc_main.o: ../ipc_main.c
	cc -c -I ../inc -I ../../lib/public -o $@ $<

shm_mgr.o: ../shm_mgr.c
	cc -c -I ../inc -I ../../lib/public -o $@ $<

