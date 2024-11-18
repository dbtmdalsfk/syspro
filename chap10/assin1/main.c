#include <stdio.h>

typedef struct {
	int data;
	struct node *next;
} Node;

typedef struct {
	Node *top;
} stack;


void push(Stack *stack, int data){
	Node *node = (Node *)malloc(sizeof(node));
	node->data = data;

	node->next = stack->top;
	stack->top = node;
}

int pop(Stack *stack)
{
	if (stack->top = NULL)
	{
		printf("stack underflow\n");
		return (-1);
	}

int main(void)
{
	stack s;

	s.top = NULL;
	push(&s, 7);
	push(&


