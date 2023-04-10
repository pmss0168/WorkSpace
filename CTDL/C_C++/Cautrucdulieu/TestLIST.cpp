#include <stdio.h>
#include <D:\Wordspace\C_C++\Cautrucdulieu\SinglyLinkedList.cpp>
int main(){
    List L;	
    Position p;

    makenullList(&L);
    L->Next=NULL;
    int i;	
    for(i=5;i>=1;i--)
        //append(2*i, &L);
        InsertList(2*i,L,&L);

    // sort(&L);
    // p=L;
    while(p->Next!=NULL){
    printf("%d ",p->Next->Element);
     p = next(p,L);
    }
    return 0;
}