#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_CAPACITY 100
#define BUFFER_LENGTH 100

typedef struct {
	char* name;
	char* number;
	char* email;
	char* group;
}Person;

Person** directory;
int capacity;
int n;

void init() {
	directory = (Person**)malloc(INIT_CAPACITY * sizeof(Person*));
	capacity = INIT_CAPACITY;
	n = 0;
}

void load(char* fileName) {
	char buffer[BUFFER_LENGTH];
	char* name, * number, * email, * group;

	FILE* fp = fopen(fileName, "r");
	if (fp == NULL) {
		printf("Open failed.\n");
		return;
	}
	while (1) {
		if (read_line(fp, buffer, BUFFER_LENGTH) <= 0)
			break;
		name = strtok(buffer, "#");
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			number = NULL;
		else
			number = strdup(token);
		token = strtok(NULL, "#");
		if (strcmp(token, " ") == 0)
			group = NULL;
		else
			group = strdup(token);
		add(strdup(name), number, email, group);
	}
	fclose(fp);
}

void add(char* name, char* number, char* email, char* group) {
	if (n >= capacity)
		reallocate();

	int i = n - 1;
	while (i >= 0 && strcmp(directory[i]->name, name) > 0) {
		directory[i + 1] = directory[i];
		i--;
	}

	directory[i + 1] = (Person*)malloc(sizeof(Person));

	directory[i + 1]->name = name;
	directory[i + 1]->number = number;
	directory[i + 1]->email = email;
	directory[i + 1]->group = group;

	n++;
}

void reallocate() {
	capacity *= 2;
	Person** tmp = (Person**)malloc(capacity * sizeof(Person*));
	for (int i = 0; i < n; i++)
		tmp[i] = directory[i];
	free(directory);
	directory = tmp;
}

void (char* name) {
	int i = search(name);
	// returns -1 if not exists
	if (i == -1) {
		printf("No person named '%s' exists.\n", name);
		return;
	}

	Person* p = directory[i];
	for (int j = i; j < n; j++)
		directory[j] = directory[j + 1];
	n--;
	release_person(p);
	printf("'%s' was deleted successfully. \n", name);
}

void realease_person(Person* p) {
	free(p->name);
	if (p->number != NULL) free(p->number);
	if (p->email != NULL) free(p->email);
	if (p->group != NULL) free(p->group);
	free(p);
}

