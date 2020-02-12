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
void load();
void save();
int search(char *name);

int main() {
    char buffer[BUFFER_SIZE];
    while (1)
    {
        printf("$ ");
        scanf("%s", buffer);

        // strcmp함수는 두 문자열이 동일하면 0을 반환한다. string compare
        if ( strcmp(buffer, "read") ==0 )
            load();
        else if ( strcmp(buffer, "add") == 0 ) 
            add();
        else if ( strcmp( buffer, "find" ) == 0 )
            find();
        else if ( strcmp( buffer, "status" ) == 0 )
            status();
        else if ( strcmp( buffer, "delete" ) == 0 )
            remove();
        else if ( strcmp( buffer, "save" ) == 0 )
            save();
        else if ( strcmp( buffer, "exit" ) == 0 )
            break;
    }
    return 0;
}

void load() {
    char fileName[BUFFER_SIZE];
    char buf1[BUFFER_SIZE];
    char buf2[BUFFER_SIZE];

    scanf("%s", fileName);  // 파일 이름을 입력 받는다.
    FILE *fp = fopen(fileName, "r");
    // 파일에 접근하기 위해서는 먼저 파일을 열어야(open) 한다.
    if (fp==NULL) {
        printf("Open failed.\n");
        return;
    }
    while (( fscanf(fp, "%s", buf1) != EOF)) {
        fscanf(fp, "%s", buf2);
        names[n] = strdup(buf1);
        numbers[n] = strdup(buf2);
        n++;
    }
    fclose(fp);
}

void save() {
    int i;
    char fileName[BUFFER_SIZE];
    char tmp[BUFFER_SIZE];

    scanf("%s", tmp);   // which is "as", discarded
    scanf("%s", fileName);

    FILE *fp = fopen(fileName, "w");
    // 파일에 쓸 때는 모드를 'w'로 하고 열어야 한다.
    if (fp == NULL) {
        printf("Open failed.\n");
        return;
    }
    for (i = 0; i < n; i++) {
        fprintf(fp, "%s %s\n", names[i], numbers[i]);
    }
    fclose(fp);
}

void add() {
    char buf1[BUFFER_SIZE], buf2[BUFFER_SIZE];
    scanf("%s", buf1);
    scanf("%s", buf2);

    int i = n-1;
    while ( i > 0 && strcmp(names[i], buf1) > 0 ) {
        names[i+1] = names[i];
        numbers[i+1] = numbers[i];
        i--;
    }
    names[i + 1] = strdup(buf1);
    numbers[i + 1] = strdup(buf2);
    // 사전식 순서로 나보다 큰 항목들은 모두 한 칸씩 뒤로 이동시키고, 처음으로 나보다 작은 항목이 나오면 그것 바로 뒤에 삽입한다.

    n++;

    printf("%s was added successfully \n", buf1);
}

void remove() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);

    int index = search(buf);    // returns -1 if not exists
    if (index == -1) {
        printf("No person named '%s' exists.\n", buf);
        return;
    }
    int j = index;
    for (; j < n-1; j++) {
        names[j] = names[j+1];
        numbers[j] = numbers[j+1];
    }

    n--;
    printf("No person named '%s' exists.\n", buf);
}

void find() {
    char buf[BUFFER_SIZE];
    scanf("%s", buf);
    int index = search(buf);
    if (index == -1)
        printf("No person named '%s' exists.\n", buf);
    else
        printf("%s\n", numbers[index]);
}

int search(char *name) {
    int i;
    for ( i = 0; i < n; i++ ) {
        if ( strcmp(name, names[i]) == 0 ) {
            return i;
        }
    }
    return -1;
}

void status() {
    int i;
    for ( i = 0; i < n; i++ )
        printf("%s %s\n", names[i], numbers[i]);
    printf("Total %d persons\n", n);
}
