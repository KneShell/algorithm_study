#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3     // 배열 ?�할?�을 ?�스?�하�??�해 ?�주 ?��? 값으�?
#define BUFFER_SIZE 50

static char ** names;
static char ** numbers;        // char * ?�?�의 배열???�름?��?�?char** ?�?�의 변?�이??

int capacity = INIT_CAPACITY;   //  size of arrays
int n = 0;      // number of people in phone directory

void init_directory();
int read_line(char str[], int limit);
void process_command();

char delim[] = " ";

int main() {
    init_directory();       // ???�수?�서 배열 names?� numbers�??�성?�다.
    process_command();      // ?�용?�의 명령??받아 처리?�는 부분을 별개???�수�?만들?�다.

    return 0;
}

void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')    //  줄바�?문자가 ?�올 ?�까지 ?�는??
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void process_command() {
    char * command_line[BUFFER_SIZE];   // ???�인???�째�??�어?�기 ?�한 버퍼
    char *command, *argument1, *argument2;

    while (1) {
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)
            // 명령줄을 ?�째�??�는??
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;
        // �?번째 ?�큰?� 명령?�이??

        if (strcmp(command, "read") == 0) {
            argument1 = strtok(NULL, delim);
            if (argument1 == NULL) {
                printf("File name requirred.\n");
                continue;
            }
            load(argument1);
        }
    }
}
