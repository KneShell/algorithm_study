#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"


#define MAX_LENGTH 100

int main() {
	char infix[MAX_LENGTH];
	read_line(stdin, infix, MAX_LENGTH);
	//	infix expression�� ���鹮�ڵ��� ���ԵǾ� �����Ƿ� scanf�� ���� �� ����.

	printf(" %s := ", infix);
	char* postfix = convert(infix);
	printf("%d\n", eval(postfix));
}