#include <stdio.h>
#include <stdlib.h>

typedef struct _queue {

    double data;
    int time;
    struct _queue* next;

} Queue;

// замыкание хвоста очереди на голову
// queue -- указатель на хвост
void enqueue(Queue** queue, double a, int t) {

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

int dequeue (Queue** queue) {

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

int read_date (Queue** queue) {

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

void input (Queue** queue) {

    if (read_date(queue)) {
        input(queue);
    }
    else {
        return;
    }
}

void queue_free (Queue** queue) {

    if (*queue) {
        dequeue(queue);
        queue_free(queue);
    }
    else {
        return;
    }

}

// * ON BRANCH MASTER
int main() {

    Queue* q = NULL;
    
    int current_time = 0;
    double current_signal = 0;
    int queue_position = 0;

    // current_time VS queue_time + queue_position

    input(&q);

    while (q) {

        if (q->next->time + queue_position == current_time) {

            current_signal = 0;

            while ((q) && (q->next->time + queue_position == current_time)) {

                current_signal = current_signal + q->next->data;
                queue_position++;
                dequeue(&q);

            }

        }

        printf("%lf\n", current_signal);
        current_time++;
    }

    queue_free(&q);

    return 0;
}