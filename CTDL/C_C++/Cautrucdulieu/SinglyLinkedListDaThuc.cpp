#include <stdio.h>
#include <stdlib.h>
typedef struct {
    double he_so;
    int bac;
} DonThuc;
struct Node{
    DonThuc e;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position DaThuc;

DaThuc nhapDaThuc(){
	DaThuc d = khoitao();
	int n;
	scanf("%d", &n);
	DonThuc a[n];
	int i;
	for (i = 0, i < n; i++){
		scanf("%d %d", &a[i].he_so, &a[i].bac);
		chenDonThuc(a[i], &d);
	}
	return d;
}
DaThuc nhanDaThuc(DaThuc D1, DaThuc D2){
	Position P = D1;
	Position Q;
	DonThuc temp;
	DaThuc D;
	D = khoitao();
	while (P->Next != NULL){
		Q = D2;
		while(Q->Next != NULL){
			temp.he_so = P->Next->e.he_so * Q->Next->e.he_so;
			temp.bac = P->Next->e.bac + Q->Next->e.bac;
			chenDonThuc(temp, &D);
			Q = Q->Next;
		}
		P = P->Next;
	}
	return D;
}
DaThuc congDaThuc(DaThuc D1, DaThuc D2){
	DaThuc D;
	D = khoitao();
	Position P = D1;
	while(P->)
}
