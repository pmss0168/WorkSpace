#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
typedef char ElementType;

typedef struct{
    ElementType Elements[MaxLength];
    int Top_idx;
}Stack;

void makenullStack(Stack *pS){
    pS->Top_idx = MaxLength;
}

int emptyStack(Stack S){
    return S.Top_idx == MaxLength;
}

int fullStack(Stack S){
    return S.Top_idx == 0;
}

ElementType top(Stack S){
    if (!emptyStack(S))
    {
        return S.Elements[S.Top_idx];
    }
    else
        printf("Error!! Empty Stack!!!");
}

void pop(Stack *pS){
    if (!emptyStack(*pS))
    {
        pS->Top_idx++;
    }
    else
        printf("Error!! Empty Stack!!");
}

void push(ElementType x, Stack *pS){
    if (!fullStack(*pS))
    {
        pS->Top_idx--;
        pS->Elements[pS->Top_idx] = x;
    }
    else
        printf("Error!! Full Stack!!!");
}