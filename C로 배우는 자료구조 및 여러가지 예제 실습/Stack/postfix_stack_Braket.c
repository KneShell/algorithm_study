#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

char OPERATORS[] = "+-*/()";
int PRECEDENCE[] = { 1, 1, 2, 2, -1, -1 };
//	여는 괄호의 우선순위를 -1로 정의하였다.

Stack operator_stack;

char* convert(char* infix) {
	operator_stack = create();

	char* postfix = (char*)malloc(strlen(infix) + 1);
	char* pos = postfix;

	char* token = strtok(infix, " ");
	while (token != NULL) {
		if (token[0] >= '0' && token[0] <= '9') {
			// operand
			sprintf(pos, "%s ", token);
			pos += (strlen(token) + 1);
		}
		else if (is_operator(token[0]) > -1) {
			// operator
			pos = process_op(token[0], pos);
		}
		else {
			handle_exception("Syntax Error: invaild chracter encountered.");
		}
		token = strtok(NULL, " ");
	}

	while (!is_empty(operator_stack)) {
		char op = (char)pop(operator_stack);
		if (op == '(')
			handle_exception("unmatched parenthesis.");
		sprintf(pos, "%c ", op);
		pos += 2;
	}
	*pos = '\0';
	return postfix;
}

char* process_op(char op, char* pos) {
	if (is_empty(operator_stack) || op == '(')
		push(operator_stack, op);
	else {
		char top_op = peek(operator_stack);
		if (precedende(op) > precendence(top_op))
			push(operator_stack, op);
		else {
			while (!is_empty(operator_stack) && precedence(op) <= precedence(top_op)) {
				pop(operator_stack);
				if (top_op == '(')
					break;
				sprintf(pos, "%c ", top_op);
				pos += 2;
				if (!is_empty(operator_stack))
					top_op = (char)peek(operator_stack);
			}
			if (op != ')')
			push(operator_stack, op);
		}
	}
	return pos;
}

int precendence(char op) {
	return PRECEDENCE[is_operator(op)];
}

int is_operator(char ch) {
	for (int i = 0; i < strlen(OPERATORS); i++)
		if (OPERATORS[i] == ch)
			return i;
	return -1;
}

void handle_exception(const char* err_msg) {
	printf("%s\n", err_msg);
	exit(1);
}
