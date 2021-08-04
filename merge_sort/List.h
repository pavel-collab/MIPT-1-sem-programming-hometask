#ifndef _LIST_H_
#define _LIST_H_

typedef struct _List {
    int day;
    int month;
    int year;
    struct _List* next;
} List;

#endif