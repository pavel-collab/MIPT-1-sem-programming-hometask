all: quantiles

quantiles.o: quantiles.c
	gcc -c quantiles.c

functions.o: functions.c
	gcc -c functions.c

quantiles: quantiles.o functions.o
	gcc -o quantiles quantiles.o functions.o

clear:
	rm *.o quantiles