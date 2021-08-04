#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "function_prototypes.h"

// замыкание хвоста очереди на голову
// queue -- указатель на хвост
void enqueue(Queue** queue, double a, int t) 
{
    Queue* box = malloc(sizeof(Queue));

    *box = (Queue) {a, t, NULL};

    if (!(*queue)) {
        box->next = box;
    }  
    else
    {
        box->next = (*queue)->next;
        (*queue)->next = box;
    }

    *queue = box;
}

int dequeue(Queue** queue) 
{
    if (!(*queue)) {
        return -1;
    }

    Queue* old = (*queue)->next;

    if (old == (*queue)) {
        *queue = NULL;
    }
    else {
        (*queue)->next = old->next;
    }

    free(old);

    return 0;
}

int read_date(Queue** queue) 
{
    double a = 0;
    int t = 0;

    if (scanf("%d %lf", &t, &a) == 2) {
        enqueue(queue, a, t);
        return 1;
    }
    else {
        return 0;
    }
}

void input(Queue** queue) 
{
    if (read_date(queue)) {
        input(queue);
    }
    else {
        return;
    }
}

void queue_free (Queue** queue) 
{
    if (*queue) {
        dequeue(queue);
        queue_free(queue);
    }
    else {
        return;
    }
}