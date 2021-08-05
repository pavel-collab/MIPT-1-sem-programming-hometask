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

/*
Пример ввода:

номер отсчета | время задержки (в отсчетах) | число для выводв
      |                       |                     |
      V                       V                     V
      -----------------------------------------------
      0)                      0                    0.1
      1)                      1                    0.2
      2)                      2                    0.3
      3)                      3                    0.4

Пример вывода:

0) 0.1 <- число 0.1 вывелось в отсчет 0 с задержкой 0
1) 0.1 <- 
2) 0.2 <- число 0.2 вывелось в отсчет 1 с задержкой 1
3) 0.2 <-
4) 0.3 <- число 0.3 вывелось в отсчет 2 с задержкой 2
5) 0.3 <-
6) 0.4 <- число 0.4 вывелось в отсчет 3 с задержкой 3
*/