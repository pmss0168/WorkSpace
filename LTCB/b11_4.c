/* 
   Ho va ten : Pham Minh Sang
   MSSV      : B2110976
   So may    : 27
   De so     : 1          
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <windows.h>
#define ml 100
//--------------Khai bao cau truc--------------
typedef struct{
	char TenHP[15];
	int SoTC;
	float Diem;
}HOCPHAN;
typedef struct{
	char MSSV[15];
	char TenSV[40];
	HOCPHAN hp[11];
}SINHVIEN;

//--------------Phan khai bao prototype cua sinh vien ---------
void docfile(char *filename, SINHVIEN a[], int *n);
void inmang(SINHVIEN a[], int n);



//--------------Ham Chinh--------------
int main(){
	FILE *f;
	int N=0;
	SINHVIEN sv[ml];
	puts("--------------Bai thuc hanh 11_4--------------");
	docfile("input11_4.txt",sv,&N);
	inmang(sv,N);
	return 0;
}


//--------------Phan cai dat ham--------------
void docfile(char *filename, SINHVIEN a[], int *n){
	int i=0,j=1;
	FILE *f;
	f=fopen(filename,"r");
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f,"%[^\t]%*c%[^\t]%*c",
				a[i].MSSV,
				a[i].TenSV);
				fscanf(f,"%[^\t]%*c%d%f%*c",
					a[i].hp->TenHP,
					a[i].hp->SoTC,
					a[i].hp->Diem);
			i++;
		}	
	}
	*n=i;
	fclose(f);
}
	
void inmang(SINHVIEN a[], int n){
	int i,j;
	printf("\n");
	for(i=0;i<n;i++){	
		printf("%3d %-40s %-10s %-8s %6d %8.1f",
			i+1,
			a[i].MSSV,
			a[i].TenSV,
			a[i].hp->TenHP,
			a[i].hp->SoTC,
			a[i].hp->Diem);
	}
	printf("\n");
}
