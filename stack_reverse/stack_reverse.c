#include <stdio.h>

int word_revers() 
{
    int c = 0;
    int s = 0;


    if (((c = getchar()) != EOF) && (c != ' ') && (c != '\t') && (c != '\n')) {
        s = word_revers();
    }

    if (c == EOF) {
        return 0;
    }
    else if (c == ' ') {
        return 1;
    }
    else if (c == '\t') {
        return 2;
    }
    else if (c == '\n') {
        return 3;
    }

    printf("%c", c);
    return s;
}

void sentense_revers() 
{
    int status = word_revers();

    if (status == 0) {
        return;
    }
    else if (status == 1) {
        printf(" ");
        sentense_revers();
    }
    else if (status == 2) {
        printf("    ");
        sentense_revers();
    }  
    else if (status == 3) {
        printf("\n");
        sentense_revers();
    } 
}

int main() 
{
    sentense_revers();
    return 0;
}