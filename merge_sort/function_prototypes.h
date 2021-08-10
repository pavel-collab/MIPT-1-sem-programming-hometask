#ifndef _FUNCTION_PROTOTYPES_H_
#define _FUNCTION_PROTOTYPES_H_

void list_insert(List** lst, int d, int m, int y);

void list_free(List* lst);

void list_print(List* lst);

void split(List* lst, List** a, List** b);

void merge(List** lst, List* a, List* b);

void sort(List** lst);

int read_list(List** lst);

void input(List** lst);

#endif