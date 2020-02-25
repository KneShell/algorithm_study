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

void add_first(char* item) {
	// ù��° ��带 ����Ű�� ������ head�� ���������� ���
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	head = temp;
}

void add_first(Node** ptr_head, char* item) {
	// ������ ���� head�� �ּҸ� �Ű������� �޴´�.
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = *ptr_head;
	*ptr_head = temp;
	/* �̷��� ������ ��� �� �Լ��� ������ ���� ȣ���ؾ��Ѵ�.
	add_first(&head, item_to_store) */
}

Node* add_first(Node* head, char* item) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = item;
	temp->next = head;
	return temp;
	/* �̷��� ������ ��� �� �Լ��� ������ ���� ȣ���ؾ��Ѵ�.
	head = add_first(head, item_to_store) */
}

int add_after(Node* prev, char* item) {
	if (prev == NULL)
		return 0;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = prev->next;
	prev->next = tmp;

	return 1;
}

Node* remove_first() {
	if (head == NULL) {
		return NULL;
	}
	else {
		Node* tmp = head;
		head = head->next;
		return tmp;
	}
}

Node* remove_after(Node* prev) {
	Node* tmp = prev->next;
	if (tmp == NULL) {
		return NULL;
	}
	else {
		prev->next = tmp->next;
		return tmp;
	}
}

Node* find(char* word) {
	/* ���Ḯ��Ʈ�� ������ ó������ ������� �湮�ϴ� ���� ��ȸ(traverse)�Ѵٰ� ���Ѵ�. �� �Լ��� �Էµ� ���ڿ� word�� ������ �ܾ ������ ��带 ã�Ƽ� �� ����� �ּҸ� ��ȯ�Ѵ�. �װ��� ���ؼ� ���� ����Ʈ�� ��ȸ�Ѵ�. */
	Node* p = head;
	while (p != NULL) {
		if (strcmp(p->data, word) == 0)
			return p;
		p = p->next;
	}
	return NULL;
}

Node* get_node(int index) {
	//	���Ḯ��Ʈ�� index��° ����� �ּҸ� ��ȯ�Ѵ�.
	if (index < 0)
		return NULL;
	Node* p = head;
	for (int i = 0; i < index && p != NULL; i++)
		p = p->next;
	return p;
}

int add(int index, char* item) {
	if (index < 0)
		return 0;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->next = NULL;

	if (index == 0) {
		add_first(item);
		return 1;
	}

	Node* prev = get_node(index - 1);
	if (prev != NULL) {
		add_after(prev, item);
		return 1;
	}
	return 0;
}

Node* remove(int index) {
	if (index < 0) {
		return NULL;
	}
	if (index == 0) {
		return remove_first();
	}

	Node* prev = get_node(index - 1);
	if (prev == NULL)
		return NULL;
	else {
		return remove_after(prev);
	}
}

Node* remove(char* item) {
	Node* p = head;
	Node* q = NULL;
	while (p != NULL && strcmp(p->data, item) != 0) {
		q = p;
		p = p->next;
	}
	if (p == NULL)
		return NULL;
	if (q == NULL)
		return remove_first();
	else
		return remove_after(q);
		
}