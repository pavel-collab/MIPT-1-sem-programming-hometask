all: queue

queue.o: queue.c
	gcc -c queue.c

functions.o: functions.c
	gcc -c functions.c

queue: queue.o functions.o
	gcc -o queue queue.o functions.o

clear:
	rm *.o queue