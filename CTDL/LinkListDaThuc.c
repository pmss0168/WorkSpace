#include<stdio.h>
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
    DaThuc D;
    int n;
    D = khoitao();
    scanf("%d ",&n);
    DonThuc a[n];
    for(int i = 1; i<= n;i++){
        scanf("%lf%d ", &a[i].he_so, &a[i].bac);
        chenDonThuc(a[i], &D);
    }
    
    return D;
}
DaThuc tinhDaoHam(DaThuc D){
    DaThuc kq;
    kq = khoitao();
    DaThuc a;
    int i = 0;
    while(D->Next != NULL){
    	a[i] = D->e.he_so * D->e.bac;
    	a[i] = D->e.bac - 1;
    	chenDonThuc(a[i], &kq);
    	i++;
	}
    return kq;
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
