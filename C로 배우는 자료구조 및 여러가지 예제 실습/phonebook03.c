#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 3     // ë°°ì´ ?¬í ?¹ì ?ì¤?¸íê¸??í´ ?ì£¼ ?ì? ê°ì¼ë¡?
#define BUFFER_SIZE 50

static char ** names;
static char ** numbers;        // char * ??ì ë°°ì´???´ë¦?´ë?ë¡?char** ??ì ë³?ì´??

int capacity = INIT_CAPACITY;   //  size of arrays
int n = 0;      // number of people in phone directory

void init_directory();
int read_line(char str[], int limit);
void process_command();

char delim[] = " ";

int main() {
    init_directory();       // ???¨ì?ì ë°°ì´ names? numbersë¥??ì±?ë¤.
    process_command();      // ?¬ì©?ì ëªë ¹??ë°ì ì²ë¦¬?ë ë¶ë¶ì ë³ê°???¨ìë¡?ë§ë¤?ë¤.

    return 0;
}

void init_directory() {
    names = (char **)malloc(INIT_CAPACITY * sizeof(char *));
    numbers = (char **)malloc(INIT_CAPACITY * sizeof(char *));
}

int read_line(char str[], int limit) {
    int ch, i = 0;

    while ((ch = getchar()) != '\n')    //  ì¤ë°ê¿?ë¬¸ìê° ?ì¬ ?ê¹ì§ ?½ë??
        if (i < limit - 1)
            str[i++] = ch;

    str[i] = '\0';

    return i;
}

void process_command() {
    char * command_line[BUFFER_SIZE];   // ???¼ì¸???µì§¸ë¡??½ì´?¤ê¸° ?í ë²í¼
    char *command, *argument1, *argument2;

    while (1) {
        printf("$ ");

        if (read_line(command_line, BUFFER_SIZE) <= 0)
            // ëªë ¹ì¤ì ?µì§¸ë¡??½ë??
            continue;

        command = strtok(command_line, delim);
        if (command == NULL) continue;
        // ì²?ë²ì§¸ ? í°? ëªë ¹?´ì´??

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
