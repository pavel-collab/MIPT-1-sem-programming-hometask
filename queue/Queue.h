#ifndef _QUEUE_H_
#define _QUEUE_H_

typedef struct _Queue 
{
    double data;
    int time;
    struct _Queue* next;
} Queue;

#endif