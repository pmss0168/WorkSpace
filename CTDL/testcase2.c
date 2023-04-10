#include<stdio.h>
#include<stdlib.h>
struct Node{
	char KyTu;
	struct Node* Next;
};
typedef struct Node* Cau;

int vitri(char ch, Cau d){
	int cnt = 1;
	while(d->Next != NULL ){
		if(d->Next->KyTu == ch){
			return cnt;
		}
		else{
		d = d->Next;
		cnt++;
		}
	}
	return -1;
}
void chenKyTu(char c, Cau *pd){
	Cau P = *pd;
	while(P->Next != NULL){
		P = P->Next;
	}
	Cau T = (struct Node*)malloc(sizeof(struct Node));
	T->KyTu = c;
	T->Next = P->Next;
	P->Next = T;
}
void chenKyTu(char  x, Cau *pL){
    Cau p = (struct Node*)malloc(sizeof(struct Node*));
    p->KyTu = x;
    p->Next = NULL;
    if(*pL == NULL){
        *pL = p;
    }
    else{
        Cau q = *pL;
        while(q->Next != NULL){
            q = q->Next;
        }
        q->Next = p;
    }
}
int sotu(Cau d){
	int cnt =0;
	if(d->Next == NULL)
		return 0;
	while(d->Next != NULL){
		if(d->Next->KyTu  == " ")
			cnt++;
		d = d->Next;
	}
	return cnt + 1;
}

//int main(){
//	struct Node* t;
//	Cau d = (struct Node*)malloc(sizeof(struct Node*));
//	d->Next = NULL;
//	t = (struct Node*)malloc(sizeof(struct Node*));
//	t->KyTu = 'e';
//	t->Next = d->Next;
//	d->Next = t;
//	t = (struct Node*)malloc(sizeof(struct Node*));
//	t->KyTu = 'f';
//	t->Next = d->Next;
//	d->Next = t;
//	printf("%d ",vitri('f',d));
//	return 0;
//}
int main(){
	struct Node *p;
	Cau d =(struct Node*)malloc(sizeof(struct Node*));
	d->Next = NULL;
	chenKyTu('A',&d);
	chenKyTu('B',&d);
	p = d;
	printf("%c%c",p->Next->KyTu, p->Next->Next->KyTu);
	return 0;
}