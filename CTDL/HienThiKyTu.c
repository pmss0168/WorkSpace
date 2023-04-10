#include<stdio.h>

struct Node{
	char KyTu;
	struct Node* Next;
};
typedef struct Node* Cau;

void hienthi(Cau d){
	printf("%c ", d->Next->KyTu);
}

int main(){
	struct Node* t = (struct Node*)malloc(sizeof(struct Node*));
	Cau d = (struct Node*)malloc(sizeof(struct Node*));
	t->KyTu = 'e';
	t->Next = d->Next;
	d->Next = t;
	hienthi(d);
	return 0;
}