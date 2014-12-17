
all: libs5ipc.so libs5ipcS.a

libs5ipc.so: shm.o
	cc -shared -o libs5ipc.so shm.o

libs5ipcS.a: shm.o
	ar cr libs5ipcS.a shm.o

shm.o: ../shm.c
	cc -fPIC -c -o shm.o -I ../public -I ../../manager/inc ../shm.c
