// алгоритм выводит число, делящее последовалельность в заданном соотношении

#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "function_prototypes.h"

int main(int argc, char* argv[]) 
{
    float q = atof(argv[1]);
    

    List* list = NULL;

    int N = 0;

    input(&list, &N);


    int n = round_function(q*(N - 1));

    int x = 0;
    quantile(list, n, &x);

    printf("%d\n", x);

    list_free(list);


    return 0;
}