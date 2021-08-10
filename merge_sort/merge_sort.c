#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "function_prototypes.h"

int main() 
{
    List* calendar = NULL;

    input(&calendar);

    sort(&calendar);

    list_print(calendar);

    list_free(calendar);

    return 0;
}