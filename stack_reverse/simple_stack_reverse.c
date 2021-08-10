#include <stdio.h>

int stack_revers() {
    int c = 0;
    if ((c = getchar()) != '\n') {
        stack_revers();
    }

    printf("%c", c);

    return 0;
}

int main() 
{
    stack_revers();
    return 0;
}