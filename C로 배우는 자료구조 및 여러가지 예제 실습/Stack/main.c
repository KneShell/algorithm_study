#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"


#define MAX_LENGTH 100

int main() {
	char infix[MAX_LENGTH];
	read_line(stdin, infix, MAX_LENGTH);
	//	infix expression에 공백문자들이 포함되어 있으므로 scanf로 읽을 수 없다.

	printf(" %s := ", infix);
	char* postfix = convert(infix);
	printf("%d\n", eval(postfix));
}