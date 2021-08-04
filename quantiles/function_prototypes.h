#ifndef _FUNCTION_PROTOTYPES_H_
#define _FUNCTION_PROTOTYPES_H_

int round_function (float value);

List* list_insert(List* lst, int element);

int list_free(List* lst);

int read_date(List** lst);

void input(List** lst, int* count);

void quantile(List* lst, int n, int* x);

#endif