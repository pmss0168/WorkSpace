#include<stdio.h>
#include"ALISTLIB.c"

int main(){
	List L;
	readList(&L);
	int x;
	scanf("%d",&x);
	printList(L);
	Position p = locate(x,L);
	while(p != L.Last+1){
		deleteList(p, &L);
		p = locate(x,L);
	}
	printList(L);
	return 0;
}