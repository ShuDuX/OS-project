hdrs = ipc.h
opts = -g -c
c_src = smoker_1.c ipc.c
c_obj = smoker_1.o ipc.o
c_src1 = smoker_2.c ipc.c
c_obj1 = smoker_2.o ipc.o
c_src2 = smoker_3.c ipc.c
c_obj2 = smoker_3.o ipc.o
p_src = producer.c ipc.c
p_obj = producer.o ipc.o
all:	producer smoker_1 smoker_2 smoker_3

smoker_1:	$(c_obj)
		gcc $(c_obj) -o smoker_1
smoker_1.o:	$(c_src) $(hdrs)
		gcc $(opts) $(c_src)
smoker_2:	$(c_obj1)
		gcc $(c_obj1) -o smoker_2
smoker_2.o:	$(c_src1) $(hdrs)
		gcc $(opts) $(c_src1)
smoker_3:	$(c_obj2)
		gcc $(c_obj2) -o smoker_3
smoker_3.o:	$(c_src2) $(hdrs)
		gcc $(opts) $(c_src2)
producer: 	$(p_obj)
		gcc $(p_obj) -o producer
producer.o: 	$(p_src) $(hdrs)
		gcc $(opts) $(p_src)
clean:
		rm smoker_1 smoker_2 smoker_3 producer *.o
