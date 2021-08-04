#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "function_prototypes.h"

void list_insert(List** lst, int d, int m, int y) 
{
    List* box = malloc(sizeof(List));

    box->day = d;
    box->month = m;
    box->year = y;

    box->next = *lst;
    *lst = box;

    #ifdef DEBUG
    if (*lst)
        printf("INSERT IS OK\n");
    else 
        printf("INSERT IS NOT OK\n");
    #endif
}

void list_free(List* lst) 
{
    if ( lst ) {
        List* next = lst->next;
        free(lst);
        list_free(next);
    }
}

void list_print(List* lst) 
{
    if (lst) {
        printf("%02d %02d %04d\n", lst->day, lst->month, lst->year);
        list_print(lst->next);
    }
}

void split (List* lst, List** a, List** b) 
{
    if (lst) {
        *a = lst;
        split(lst->next, b, &(*a)->next);
    }
    else {
        *a = NULL;
        *b = NULL;
    }
}

void merge(List** lst, List* a, List* b) 
{

    if (a && b) {

        if (a->year < b->year) {
            *lst = a;
            merge(&a->next, a->next, b);
        }
        else if (a->year > b->year) {
            *lst = b;
            merge(&b->next, a, b->next);
        }
        else if (a->month < b->month) {
            *lst = a;
            merge(&a->next, a->next, b);
        }
        else if (a->month > b->month) {
            *lst = b;
            merge(&b->next, a, b->next);
        }
        else if (a->day <= b->day) {
            *lst = a;
            merge(&a->next, a->next, b);
        }
        else {
            *lst = b;
            merge(&b->next, a, b->next);
        }

    }
    else {
        if (!a) {
            *lst = b;
        }
        else {
            *lst = a;
        }
    }
}

void sort(List** lst) 
{
    if (!*lst || !(*lst)->next) {
        return;
    }

    List* a = NULL;
    List* b = NULL;

    split(*lst, &a, &b);
    sort(&a);
    sort(&b);
    merge(lst, a, b);

    #ifdef DEBUG
    if (*lst)
        printf("SORT IS OK\n");
    else 
        printf("SORT IS NOT OK\n");
    #endif
}

int read_list(List** lst) 
{
    int day = 0;
    int month = 0;
    int year = 0;

    if (scanf("%d %d %d", &day, &month, &year) == 3) {
        list_insert(lst, day, month, year);
        return 1;
    }
    else {
        return 0;
    }
}

void input(List** lst) 
{
    if (read_list(lst)) {
        input (lst);
    }    
}
