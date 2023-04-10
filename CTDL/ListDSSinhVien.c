#include<stdio.h>
#include<string.h>
//#include"AListLib.c"
typedef struct{
    char MSSV[10];
    char HoTen[50];
    float DiemLT, DiemTH1, DiemTH2;
}SinhVien;
//struct SinhVien{
//    char MSSV[10];
//    char HoTen[50];
//    float DiemLT, DiemTH1, DiemTH2;
//};
typedef struct{
    SinhVien A[40];
    int n;
}DanhSach;
//-----------------Cai dat ham-----------------------------
void dsRong(DanhSach *L){
	L->n = 0;
}
void chenCuoi(SinhVien s, DanhSach *pL){
    if(pL->n >= 40)
        printf("Loi! Danh sach day!");
    else{
        pL->A[pL->n] = s;
        pL->n++;
    }
        
}
DanhSach chepKhongDat(DanhSach L){
	DanhSach kq;
	dsRong(&kq);
	for(int i = 0; i < L.n; i++){
		if((L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2) < 4)
			chenCuoi(L.A[i], &kq);
	}
	return kq;
}
void hienthi(DanhSach L){
    for(int i = 0; i < L.n; i++){
        printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, (L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2));
    }
}
void hienthi1(DanhSach L){
    for(int i = 0; i < L.n; i++){
        printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2);
    }
}
void hienthiDat(DanhSach L){
	for(int i = 0; i < L.n; i++){
		if((L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2) >= 4)
			printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n",L.A[i].MSSV, L.A[i].HoTen, L.A[i].DiemLT, L.A[i].DiemTH1, L.A[i].DiemTH2, (L.A[i].DiemLT + L.A[i].DiemTH1 + L.A[i].DiemTH2));
	}
}
int tim(char x[10], DanhSach L){
    int p = 0;
    for(int i = 0; i < L.n; i++){
        if(strcmp(x,L.A[i].MSSV) == 0)
            p = i + 1;
        else
            p = L.n + 1;
        
    }
    return p;
}
void xoaTai(int p, DanhSach *pL){
    if(p < 0){
        printf("Vi tri khong hop le!!!");
    }else{
        for(int i = p; i < pL->n; i++){
            pL->A[i] = pL->A[i+1];
            pL->n--;
        }
    }
}
void xoa(char x[10], DanhSach *pL){
	for(int i = 0; i < pL->n; i++){
		if(strcmp(x, pL->A[i].MSSV) == 0){
			pL->A[i] = pL->A[i+1];
			pL->n--;
		}
	}
	
}
int ktRong(DanhSach L){
    if(L.n == 0)
        return 1;
    else 
        return 0;
}
void xoaSinhVien(char x[10], DanhSach *pL){
	int p = 0;
	while(p < pL->n){
		if(strcmp(x,pL->A[p].MSSV)==0){
			pL->A[p] = pL->A[p+1];
			pL->n--;
		}
		p++;
	}
}
//DanhSach nhap(){
//	DanhSach L, kq;
//	char hoten[50], mssv[10];
//	dsRong(&kq);
//	scanf("%d ",&L.n);
//	scanf("\n");
//	for(int i = 0; i < L.n; i++){
//		fgets(mssv,sizeof(mssv)+1,stdin);
//        if(mssv[strlen(mssv)-1] == '\n') 
//			mssv[strlen(mssv)-1] = '\0';
//        strcpy(L.A[i].MSSV,mssv);
//        fgets(hoten,sizeof(hoten)+1,stdin);
//        if(hoten[strlen(hoten)-1] == '\n') 
//			hoten[strlen(hoten)-1] = '\0';
//        strcpy(L.A[i].HoTen,hoten);
//		scanf("%f%f%f ",&L.A[i].DiemLT, &L.A[i].DiemTH1, &L.A[i].DiemTH2);
//		if(tim(L.A[i].MSSV, kq) == kq.n+1)
//			chenCuoi(L.A[i], &kq);
//	}
//	return kq;
//}
DanhSach nhap(){
	SinhVien L;
	DanhSach kq;
	char hoten[50], mssv[10];
	float diemlt, diemth1, diemth2;
	int n;
	dsRong(&kq);
	scanf("%d ",&n);
	for(int i = 0; i < n; i++){
		scanf("\n");
		fgets(mssv,sizeof(mssv)+1,stdin);
        if(mssv[strlen(mssv)-1] == '\n') 
			mssv[strlen(mssv)-1] = '\0';
        strcpy(L.MSSV,mssv);
        fgets(hoten,sizeof(hoten)+1,stdin);
        if(hoten[strlen(hoten)-1] == '\n') 
			hoten[strlen(hoten)-1] = '\0';
        strcpy(L.HoTen,hoten);
		scanf("%f%f%f ",&diemlt, &diemth1, &diemth2);
		L.DiemLT = diemlt;
		L.DiemTH1 = diemth1;
		L.DiemTH2 = diemth2;
		chenCuoi(L, &kq);
	}
	return kq;
}
//---------------------------------------------------------
int main(){
	DanhSach L;
	char MSSV[10];
	int p;
	L = nhap();	
	fgets(MSSV,sizeof(MSSV)+1,stdin);
	p=tim(MSSV,L);
	hienthi1(L);
	if(strcmp(MSSV, L.A[p-1].MSSV) == 0){
		printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", MSSV);
		printf("%s - %s - %.2f - %.2f - %.2f\n",L.A[p-1].MSSV, L.A[p-1].HoTen, L.A[p-1].DiemLT, L.A[p-1].DiemTH1, L.A[p-1].DiemTH2);
		xoa(MSSV, &L);
	}
	else
		printf("Khong tim thay sinh vien %s", MSSV);
	return 0;
}