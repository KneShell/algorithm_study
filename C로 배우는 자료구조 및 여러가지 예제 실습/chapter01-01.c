#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int * array = (int *)malloc(4*sizeof(int));
    array[0] = 1;
    array[1] = 2;
    array[3] = 3;

    int * tmp = (int *)malloc(8*sizeof(int));
    int i;
    for (i=0; i<4; i++)
        tmp[i] = array[i];

    array = tmp;

    array[4] = 4;
    array[5] = 5;
    array[6] = '\0';

    printf("\n %d", array[5]);
}
