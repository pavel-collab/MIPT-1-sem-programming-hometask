#ifndef _FUNCTION_PROTOTYPES_H_
#define _FUNCTION_PROTOTYPES_H_

void enqueue(Queue** queue, double a, int t);

int dequeue(Queue** queue);

int read_date(Queue** queue);

void input (Queue** queue);

void queue_free(Queue** queue);

#endif