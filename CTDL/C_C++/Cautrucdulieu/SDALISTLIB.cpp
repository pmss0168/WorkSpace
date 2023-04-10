#include <stdio.h>
#include <D:\Wordspace\C_C++\Cautrucdulieu\ALISTLIB.cpp>
int main(int argc, char const *argv[]){
    List L1,L2,L;
    int i;

    makenullList(&L1);
    makenullList(&L2);

    for(i=5;i>=0;i--){
        insertSet(2*i, &L1);
    }
    for(i=9;i>=4;i--){
        insertSet(2*i, &L2);
    }

    for(i=0;i<L1.Last;i++){
        printf("%d ",L1.Elements[i]);
    }
    printf("\n");
    for(i=0;i<L2.Last;i++){
        printf("%d ",L2.Elements[i]);
    }
    printf("\n");
    intersection(L1,L2,&L);
    for(i=0;i<L.Last;i++){
        printf("%d ",L.Elements[i]);
    }
    return 0;
}
