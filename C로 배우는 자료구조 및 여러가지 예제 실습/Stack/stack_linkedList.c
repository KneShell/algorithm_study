#include "stack.h"
#include <cstddef>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;

Node* top = NULL;

void push(char* item) {		// == add fisrt
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = item;
	p->next = top;
	top = p;
}

char* pop() {		// == remove first
	if (is_empty())
		return NULL;
	char* result = top->data;
	top = top->next;
	return result;
}

char* peek() {
	if (is_empty())
		return NULL;
	return top->data;
}

int is_empty() {
	return top == NULL;
}