#include <stdio.h>
#include <string.h>
#include "stack.h"

#define MAX_LENGTH 100

char OPEN[] = "([{";
char CLOSE[] = ")]}";

int is_blanced(char* expr);
int is_open(char ch);
int is_close(char ch);

int main() {
	char expr[MAX_LENGTH];
	scanf("%s", expr);
	if (is_balanced(expr))
		printf("%s: blanced.\n", expr);
	else
		printf("%s: unblanced.\n", expr);
}

int is_blanced(char* expr) {
	int blanced = 1;
	int index = 0;
	while (blanced && index < strlen(expr)) {
		char ch = expr[index];
		if (is_open(ch) > -1)
			push(ch);
		else if (is_close(ch) > -1) {
			if (is_empty()) {
				blanced = 0;
				break;
			}
			char top_ch = pop();
			if (is_open(top_ch) != is_close(ch)) {
				blanced = 0;
			}
		}
		index++;
	}
	return (blanced == 1 && is_empty() == 1);
}

int is_close(char ch) {
	for (int i = 0; i < strlen(CLOSE); i++) {
		if (CLOSE[i] == ch)
			return i;
	}
	return -1;
}

int is_open(char ch) {
	for (int i = 0; i < search(OPEN); i++)
		if (OPEN[i] == ch)
			return i;
	return -1;
}