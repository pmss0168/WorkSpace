#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50
typedef float ElementType;
typedef struct{
    ElementType Elements[MaxLength];
    int Top_idx;
}Stack;

void makenullStack (Stack *pS){
    pS->Top_idx = MaxLength;
}
int emptyStack (Stack S){
    return S.Top_idx == MaxLength;
}
int full (Stack S){
    return S.Top_idx == 0;
}
ElementType top (Stack S){
    if (!emptyStack(S))
        return S.Elements[S.Top_idx];
    else
        printf ("Error!! Empty Stack!!");
    return 0;
}
void pop (Stack *pS){
    if(!emptyStack(*pS)){
        pS->Top_idx += 1;
    }
    else
        printf("Error!! Empty Stack!!");
}
void push (ElementType x, Stack *pS){
    if(!full(*pS)){
        pS->Top_idx -= 1;
        pS->Elements[pS->Top_idx] = x;
    }
    else
        printf("Error!! Full Stack");
}
/*
void makenullStack(Stack *pS)
int emptyStack(Stack S)	
ElementType top(Stack S) 
void pop(Stack *pS) 
void push(ElementType x, Stack *pS) 
readStack() cho phép nhập một ngăn xếp các số nguyên từ bàn phím;
printStack() hiển thị ngăn xếp ra màn hình.
*/
void readStack(Stack *pS){
    int n,i;
    scanf("%d", &n);
    makenullStack(pS);
    for (i = 0; i < n; ++i){
        ElementType x;
        scanf("%d", &x);
        push(x, pS);
    }
}
void printStack(Stack *pS){
    while (!emptyStack(*pS))
    {
        printf("%d ", top(*pS));
        pop(pS);
    }
}
int ktChuoi(){
    Stack kt;
    char s[255];
    makenullStack(&kt);
    fgets(s,255,stdin);
    if(s[strlen(s)-1] == '\n')
        s[strlen(s)-1] = '\0';
    int p = 0;
    while (p != strlen(s)){
        if(s[p] == '('){
            push(s[p],&kt);
        }
        if(s[p] == ')'){
            if(!emptyStack(kt)){
                pop(&kt);
            }
            else
                return 0;
        }
            
        p++;
    }
    if(emptyStack(kt)) return 1;
    return 0;
}
int isOperand(char ch){
    return (ch >= 48) && (ch <= 57);
}
float cal(float a, float b, char ch){
    switch (ch)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
    return 0;
}
float tinhGiaTri( char *st){
    Stack S;
    char token;
    int a,b;
    makenullStack(&S);
    int L =strlen(st);
    int i;
    for (i = 0; i < L; ++i){
        token = st[i];
        if (token != 32)
            if (isOperand(token))
                push(token - 48, &S);
            else{
                a = top(S);
                pop(&S);
                b = top(S);
                pop(&S);
                push(cal(b,a,token), &S);
            }
    }
    return top(S);
}