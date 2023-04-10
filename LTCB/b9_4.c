/* 
   Ho va ten : Pham Minh Sang
   MSSV      : B2110976
   So may    : 27
   De so     : 1          
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <windows.h>

#define ml 100 //Maxlength: so hoa don toi da
#define TAB 9
//--------------Khai bao cau truc--------------
typedef struct{
  char TenSV[40];
  int DRL;
  char XL[15];
}SINHVIEN;


//--------------Phan khai bao prototype cua sinh vien ---------
void inmang(SINHVIEN a[], int n);
void docfile(char *filename, SINHVIEN a[], int *n);
void xeploai(SINHVIEN *a, int n);
void sapxep(SINHVIEN a[],int n);


// Chuong trinh chinh
int main() { 
	FILE *f1;   
	SINHVIEN sv[ml];
	int N=0;	
	puts("--------KIEM TRA THUC HANH C-LAN 2--------");
	docfile("input9_4.txt",sv,&N);
	xeploai(sv,N);
	sapxep(sv,N);
	inmang(sv,N);
			
	return 0;
}




//---------Phan cai dat ham cua sinh vien---------------
void docfile(char *filename, SINHVIEN a[], int *n){
	FILE *f;
	int i=0;
	f=fopen(filename,"r");
	while(!feof(f)){
		fscanf(f,"%[^\n]%*c%d%*c",a[i].TenSV,&a[i].DRL);
		i++;
	}
	*n=i;
	fclose(f);
}
void xeploai(SINHVIEN *a, int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i].DRL>=55)
			strcpy(a[i].XL,"Trung Binh");
			if(a[i].DRL>=70)
				strcpy(a[i].XL,"Kha");
				if(a[i].DRL>=85)
					strcpy(a[i].XL,"Gioi");
	}
}
void sapxep(SINHVIEN a[],int n){
	int i,j;
	SINHVIEN temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(a[i].DRL>a[j].DRL){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
}
void inmang(SINHVIEN a[], int n){
	int i;
	printf("\n");
	printf(" ------------------------------------------------- \n");
	printf("| STT | HO VA TEN         |   DRL  |  XL          |\n");
	printf("|-----+-------------------+--------+--------------|\n");
	for(i=0;i<n;i++){
		printf("|  %-2d | %-17s |   %-3d  |  %-11s |\n",
			i+1,
			a[i].TenSV,
			a[i].DRL,
			a[i].XL);
	}
	printf(" -------------------------------------------------");
	printf("\n");
}






