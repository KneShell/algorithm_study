#define BUFFER_SIZE 100
#include <stdio.h>
#include <string.h>

int main(void) {
    
    char *words[100];
    int n = 0; // number of strings
    char buffer[BUFFER_SIZE];
    while (n<4 && scanf("%s", buffer) != EOF) // scanf("%d", &a)
    {
        words[n] = strdup(buffer);
        n++;
    }
    
    for (int i=0; i<4; i++)
        printf("%s\n", words[i]);
}
