#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100
typedef struct {
	int data[MAX_ELEMENTS];
	int size;
} Stack;

void make_null_stack(Stack* S){
	S->size = 0;
}

void push(Stack* S, int x){
	S->data[S->size] = x;
	S->size++;
}

int top(Stack* S){
	return S->data[S->size - 1];
}

void pop(Stack* S){
	S->size--;
}

int empty(Stack* S){
	return S->size == 0;
}
