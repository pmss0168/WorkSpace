#include<stdio.h>
#include<stdlib.h>
#define MAX_ELEMENTS 100

typedef struct{
	int data[MAX_ELEMENTS];
	int front, rear;
}Queue;
void make_null_queue(Queue* Q){
	Q->front = 0;
	Q->rear = -1;
}
void push(Queue* Q, int x){
	Q->rear++;
	Q->data[Q->rear] = x;
}
int top(Queue* Q){
	return Q->data[Q->front];
}
void pop(Queue* Q){
	Q->front++;
}
int empty(Queue* Q){
	return Q->front > Q->rear;
}
