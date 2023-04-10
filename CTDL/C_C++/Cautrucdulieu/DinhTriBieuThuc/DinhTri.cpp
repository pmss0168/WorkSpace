#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        return S.Elements[S.Top_idx];
    else
        printf("Error!! Empty Stack!!!");
    return 0;
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

// int toanHang(char ch){
//     return ((ch >= 48) && (ch <= 57)) || ((ch >= 'a') && (ch <= 'z'));
// }

// int mucUutien(char ch){
//     if(ch == '+' || ch == '-')
//         return 1;
//     if(ch == '*' || ch == '/')
//         return 2;
//     return 0;
// }

// void themStr(char *Str, char ch){
//     int L = strlen(Str);
//     Str[L] = ch;
//     Str[L + 1] = '\0';
// }
// int checktoantu(char ch){
//     switch (ch)
//     {
//     case '+':
//         return 1;
//         break;
//     case '-':
//         return 1;
//         break;
//     case '*':
//         return 1;
//         break;
//     case '/':
//         return 1;
//         break;
//     }
//     return 0;
// }
// // Doi bieu thuc trung to thanh hau to
// void chuyenHauto(char *inExp, char *posExp){
//     Stack S;
//     makenullStack(&S);
//     int i;
//     int maxLen = strlen(inExp);
//     char token;
//     for (i = 0; i < maxLen; ++i){
//         token = inExp[i];
//         if (toanHang(token)) themStr(posExp, token);

//         else    if (token == '(') push(token, &S);
//                 else    if (token == ')'){
//                             while (top(S) != '(' && !emptyStack(S))
//                                 {
//                                     themStr(posExp, top(S));
//                                     pop(&S);
//                                 }
//                             pop(&S);
//                         }
//         else if(checktoantu(token)){
//                  while ( (!emptyStack(S)) && top(S) != '(' && (mucUutien(top(S))>=mucUutien(token)) )
//                     {
//                         themStr(posExp, top(S));
//                         pop(&S);
//                     }
//                 push(token, &S);
//             }
        
//     }
//     while (!emptyStack(S))
//         {
//             themStr(posExp, top(S));
//             pop(&S);
//         }
    // for (int i = 0; i < maxLen; i++)
    // {
    //     token = inExp[i];
    //     if ((token >= '0' && token <= '9') || (token >= 'a' && token <= 'z'))
    //     {
    //         themStr(posExp, token);
    //     }
        
    //     else if (token == '(')
    //     {
    //         push(token, &S);
    //     }
        
    //     else if (token == ')')
    //     {
    //         while (!emptyStack(S) && top(S) != '(')
    //         {
    //             themStr(posExp, top(S));
    //             pop(&S);
    //         }
    //         pop(&S);
    //     }
        
    //     else if (token == '+' || token == '-' || token == '*' || token == '/')
    //     {
    //         while (!emptyStack(S) && (top(S) != '(') && (mucUutien(token) <= mucUutien(top(S))))
    //         {
    //             themStr(posExp, top(S));
    //             pop(&S);
    //         }
    //         push(token, &S);
    //     }
    // }
    // while (!emptyStack(S))
    // {
    //     token = top(S);
    //     themStr(posExp, token);
    //     pop(&S);
    // }
//}
// void chuyenHauto(char *Infix, char *Posfix){
//     Stack S;
//     makenullStack(&S);
//     int i, L = strlen(Infix);
//     char Token;

//     for ( i = 0; i < L; ++i)
//     {
//         Token = Infix[i];
//         if (Token != 32)
//         {
//             if (toanHang(Token))
//             {
//                 themStr(Posfix, Token);
//             }
//             else
//             {
//                 if (Token == '(')
//                     push('(', &S);
//                 else if (Token == ')')
//                 {
//                     while (top(S) != '(')
//                     {
//                         themStr(Posfix, top(S));
//                         pop(&S);
//                     }
//                     pop(&S);
//                 }
//                 else{
//                     while (!emptyStack(S) && (mucUutien(top(S))>=mucUutien(Token)))
//                     {
//                         themStr(Posfix, top(S));
//                         pop(&S);
//                     }
//                     push(Token, &S);
//                 }
                
//             }
            
//         }
//         while (!emptyStack(S))
//             {
//                 themStr(Posfix, top(S));
//                 pop(&S);
//             }
//     }
    
// }
// Dinh thuc bieu thuc Hau to

// int tinhToan(int a, int b, char toanhang){
//     switch (toanhang)
//     {
//     case '+':
//         return a + b;
//         break;
//     case '-':
//         return a - b;
//         break;
//     case '*':
//         return a * b;
//         break;
//     case '/':
//         return a / b;
//         break;
//     }
//     return 0;
// }
// float tinhGiaTri( char *st){
//     Stack S;
//     char token;
//     int a,b;
//     makenullStack(&S);
//     int L =strlen(st);
//     int i;
//     for (i = 0; i < L; ++i){
//         token = st[i];
//         if (token != 32)
//             if (toanHang(token))
//                 push(token - 48, &S);
//             else{
//                 a = top(S);
//                 pop(&S);
//                 b = top(S);
//                 pop(&S);
//                 push(tinhToan(b,a,token), &S);
//             }
//     }
//     return top(S);
// }
char doiSo(int n){
    char x;
    switch (n)
    {
    case 10:
        x = 'A';
        break;
    case 11:
        x = 'B';
        break;
    case 12:
        x = 'C';
        break;
    case 13:
        x = 'D';
        break;
    case 14:
        x = 'E';
        break;
    case 15:
        x = 'F';
        break;
    }
    return x;
}
void doiThaplucphan(int n, Stack *pS){
    makenullStack(pS);
    int temp = n / 16;
    while (n > 0)
    {
        temp = n % 16;
        if (temp >=0 && temp <=9)
        {
            push(temp + '0',pS);
        }
        else    if(temp >= 10 && temp <= 15)
                    push(doiSo(temp),pS);
        n = n / 16;
    }
    
}
void hienthi(Stack *pS){
    while (!emptyStack(*pS))
    {
        printf("%c", top(*pS));
        pop(pS);
    }
}
int main(int argc, char const *argv[])
{
    Stack S;
    doiThaplucphan(50,&S);
    hienthi(&S);
}
