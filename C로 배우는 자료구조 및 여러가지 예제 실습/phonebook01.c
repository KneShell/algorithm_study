#include <stdio.h>
#include <string.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

static char * names[CAPACITY];     // names
static char * numbers[CAPACITY];   // phone numbers 051-4023-2144
static int n = 0;                  // number of people in phone directory

void add();
void find();
void status();
void remove();

int main() {
    char command[BUFFER_SIZE];
    while (1)
    {
        printf("$ ");
        scanf("%s", command);

        // strcmp함수는 두 문자열이 동일하면 0을 반환한다. string compare
        if ( strcmp(command, "add") == 0 ) 
            add();
        else if ( strcmp( command, "find" ) == 0 )
            find();
        else if ( strcmp( command, "status" ) == 0 )
            status();
        else if ( strcmp( command, "delete" ) == 0 )
            remove();
        else if ( strcmp( command, "exit" ) == 0 )
            break;
    }
    return 0;
}

void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    // strdup(string) == string duplication 인자로 받은 문자열을 복사해 리턴
    // strcpy(srting1, string2) == string copy 인자를 2개 받아 두번째 인자를 첫번쨰 인자에 삽입
    names[n] = strdup(buf1);
    //buf1은 스택에 할당된 메모리이므로 add 함수가 return되고 나면 소멸된다. 따라서 buf1에 저장된 문자열을 복제한 후 배열 names[0]에 복제된 배열의 주소를 저장해야 한다. 복제된 배열은 strdup 함수 내에서 malloc으로 (heap에) 할당된 메모리이므로 add 함수가 종료된 후에도 소멸하지 않는다.
    numbers[n] = strdup(buf2);
    n++;

    printf("%s was added successfully \n", buf1);
}

void find() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int i;
    for (i = 0; i < n; i++) {
        if ( strcmp(buf, names[i]) == 0)  {
            printf("%s\n", numbers[i]);
            return;
        }
    }
    printf("No person named '%s' exists.\n", buf);
}

void status() {
    int i;
    for ( i = 0; i < n; i++ )
        printf("%s %s\n", names[i], numbers[i]);
    printf("Total %d person.\n", n);
}

void remove() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int i;
    for ( i = 0; i < n; i++ ) {
        if ( strcmp(buf, names[i]) == 0 ) {
            names[i] = names[n-1];
            numbers[i] = numbers[n-1];  // 맨 마지막 사람을 삭제된 자리로 옮긴다.
            n--;
            printf(" '%s' was deleted successfully. \n", buf);
            return;
        }
    }
    printf("No person named '%s' exists.\n", buf);
}

