all: merge_sort

functions.o:
	gcc -c functions.c

merge_sort.o:
	gcc -c merge_sort.c

merge_sort: merge_sort.o functions.o
	gcc -o merge_sort merge_sort.o functions.o

clear:
	rm *o merge_sort