#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

int read_line(char str[], int n);

int main(void) {
    char buffer[BUFFER_SIZE];
    while (1)
    {
        printf("$ ");
        fgets(buffer, BUFFER_SIZE, stdin);
        int len = read_line(buffer, BUFFER_SIZE);
        printf("%s:%d\n", buffer, len);
    }
}

int read_line( char str[], int limit ) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')
        if (i < limit)
            str[i++] = ch;

    str[i] = '\0';
    return i;
}