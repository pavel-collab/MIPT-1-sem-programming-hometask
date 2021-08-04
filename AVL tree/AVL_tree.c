#include <stdio.h>
#include <stdlib.h>

#include "Tree.h"
#include "function prototypes.h"

int main() {

    Tree* test = NULL;
    int a = 0;


    while (scanf("%d", &a) == 1) {
        tree_insert(&test, a);
    }

    printf("\n");
    tree_walk(test, 0);
    printf("\n");

    int left_N = 0;
    int right_N = 0;

    root_count(test->Left, &left_N);
    root_count(test->Right, &right_N);

    printf("\n%d %d", left_N, right_N);

    tree_free(test);

    return 0;
}