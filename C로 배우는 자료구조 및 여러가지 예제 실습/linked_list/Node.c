#include <stdio.h>

struct node {
	char* data;
	struct node* next;
};

typedef struct node Node;
Node* head = NULL;

int main() {
	head = (Node*)malloc(sizeof(Node));
	head->data = "Tuseday";
	head->next = NULL;

	Node* q = (Node*)malloc(sizeof(Node));
	q->data = "Thursday";
	q->next = NULL;
	head->next = q;

	q = (Node*)malloc(sizeof(Node));
	q->data = "Monday";
	q->next = head;
	head = q;

	Node* p = head;
	while (p != NULL) {
		printf("%s\n", p->data);
		p = p->next;
	}
}