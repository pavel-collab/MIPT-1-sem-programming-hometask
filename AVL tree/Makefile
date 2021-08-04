all: AVL_tree

AVL_tree.o: AVL_tree.c
	gcc -c AVL_tree.c

functions.o: functions.c
	gcc -c functions.c

AVL_tree: AVL_tree.o functions.o
	gcc -o AVL_tree AVL_tree.o functions.o

clear:
	rm *.o AVL_tree