// couunt of numbers <= x n = Q(N - 1)

#include <stdio.h>
#include <stdlib.h>

int round_function (float value) {
    
    if (value > 0)
        return (int) (value += 0.5);
    else
        return (int) (value -= 0.5);      

}

typedef struct _list{
    int date;
    struct _list *next;
} List;

List* list_insert(List* lst, int element) {

    if ((lst == NULL) || (lst->date >= element)) {

        List* box = malloc(sizeof(List));
        box->date = 0;      
        box->date = element;   

        box->next = lst;
        return box;
    }
    else {
        lst->next = list_insert(lst->next, element);
        return lst;
    }

}

int list_free(List* lst) {

    if (lst != NULL) {
        List* box = lst->next;
        free(lst);
        list_free(box);
    }
    return 0;

}

int read_date(List** lst) {

    int a = 0;

    if (scanf("%d", &a) == 1) {
        *lst = list_insert(*lst, a);
        return 1;
    }
    else {
        return 0;
    }

}

void input(List** lst, int* count) {

    if (read_date(lst) == 1) {
        (*count)++;
        input(lst, count);
    }

}

void quantile(List* lst, int n, int* x) {

    if (n > 0) {
        quantile(lst->next, n - 1, x);
    }
    else {
        *x = lst->date;
    }

}

int main(int argc, char* argv[]) {

    float q = atof(argv[1]);
    

    List* list = NULL;

    int N = 0;

    input(&list, &N);


    int n = round_function(q*(N - 1));

    int x = 0;
    quantile(list, n, &x);

    printf("%d\n", x);

    list_free(list);


    return 0;
}