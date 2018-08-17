srcs = re4.c
objs = re4.o
opts = -g -c
all: re4
re4:	$(objs)
	gcc $(objs) -o re4
re4.o:	$(srcs)
	gcc $(opts) $(srcs)
clean:
	rm re4	*.o
srcs = res.c
objs = res.o
opts = -g -c
all: res
res:	$(objs)
	gcc $(objs) -o res
res.o:	$(srcs)
	gcc $(opts) $(srcs)
clean:
	rm res	*.o
