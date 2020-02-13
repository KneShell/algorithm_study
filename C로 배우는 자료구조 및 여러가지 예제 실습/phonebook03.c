#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3     // 배열 재할당을 테스트하기 위해 아주 작은 값으로
#define BUFFER_SIZE 50

static char ** names;
static char ** numbers;        // char * 타입의 배열의 이름이므로 char** 타입의 변수이다.

int capacity = INIT_CAPACITY;   //  size of arrays
int n = 0;      // number of people in phone directory

void init_directory();
int read_line(char str[], int limit);
void process_command();

char delim[] = " ";

int main() {
    init_directory();       // 이 함수에서 배열 names와 numbers를 생성한다.
    process_command();      // 사용자의 명령을 받아 처리하는 부분을 별개의 함수로 만들었다.

    return 0;
}

void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')    //  줄바꿈 문자가 나올 때까지 읽는다.
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void process_command() {
    char * command_line[BUFFER_SIZE];   // 한 라인을 통째로 읽어오기 위한 버퍼
    char *command, *argument1, *argument2;

    while (1) {
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)
            // 명령줄을 통째로 읽는다.
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;
        // 첫 번째 토큰은 명령어이다.

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
