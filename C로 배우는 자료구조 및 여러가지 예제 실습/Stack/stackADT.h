#pragma once
#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h> /* C99 only */

typedef int Item;
/*	재사용성을 위해 데이터 타입을 변수 처럼 재정의 해놓았다
  예를들어, 스택의 데이터 타입을 float으로 바꾸는 경우 Item하나만 재정의하면 된다.
*/

typedef struct stack_type* Stack;

Stack create();
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);
Item peek(Stack s);

#endif // !STACKADT_H
