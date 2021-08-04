#include <stdio.h>
#include <stdlib.h>

#include "Queue.h"
#include "function_prototypes.h"

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