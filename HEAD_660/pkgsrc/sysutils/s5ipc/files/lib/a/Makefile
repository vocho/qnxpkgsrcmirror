
libs5ipc.a: shm.o
	ar cr libs5ipc.a shm.o
	

shm.o: ../shm.c
	cc -c -o shm.o -I ../public -I ../../manager/inc ../shm.c
