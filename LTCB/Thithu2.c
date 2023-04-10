/* 
   Ho va ten : Pham Minh Sang
   MSSV      : B2110976
   So may    : 27
   De so     : 1          
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <windows.h>

#define ML 100 //Maxlength: so hoa don toi da
#define TAB 9
typedef struct{
  char MaSach[15];	
  char TenSach[50];	
  int SL; 	// So luong
  float DG;	// Don gia, don vi tinh ngan dong
}HOADON;


//--------------Phan khai bao prototype---------
void InMang(HOADON a[], int N);
void docfile(char *filename, HOADON a[], int *n);
void SLmax(HOADON a[], int n);
double TongCK(HOADON a[], int n);
void capnhat(char *m, int sl, HOADON a[], int n);


// Chuong trinh chinh
int main() { 
	FILE *f;   
	HOADON hd[ML];
	HOADON x;
	char m[15];
	int sl;	
	int N=0;	
	puts("--------KIEM TRA THUC HANH C-LAN 2--------");
	docfile("input1.txt",hd,&N);
	//Them mot ma sach
	strcpy(x.MaSach,"CT101");
	strcpy(x.TenSach,"Lap trinh can ban C");
	x.SL=100;
	x.DG=50;
	hd[N]=x;
	N++;
	InMang(hd,N);
	SLmax(hd,N);
	printf("\nTong chiet khau la:\n%.1f",TongCK(hd,N));
	printf("\nNhap ma sach cap nhat:");
	fgets(m,15,stdin);
	if(m[strlen(m)-1]=='\n')
		m[strlen(m)-1]='\0';
	printf("\nNhap so luong can cap nhat:");
	scanf("%d",&sl);
	capnhat(m,sl,hd,N);
	InMang(hd,N);		
	return 0;
}
//---------Phan cai dat ham---------------
void docfile(char *filename, HOADON a[], int *n){
	int i=0;
	FILE *f;
	f=fopen(filename,"r");
	while(!feof(f)){
		fscanf(f,"%[^\t]%*c%[^\t]%*c%d%f%*c",
			a[i].MaSach,
			a[i].TenSach,
			&a[i].SL,
			&a[i].DG);
		i++;
	}
	*n=i;
	fclose(f);
}

void SLmax(HOADON a[], int n){
	int i,j;
	HOADON temp;
	temp.SL=a[0].SL;
	for(i=1;i<n;i++){
			if(temp.SL<a[i].SL){
				temp.SL=a[i].SL;
				j=i;
			}
	}
	printf("Hoa don co so luong lon nhat la:\n");
	printf("%s	%s	%d	%.1f",a[j].TenSach,a[j].MaSach,temp.SL,a[j].DG);
}

double TongCK(HOADON a[], int n){
	int i;
	double tong=0;
	for(i=0;i<n;i++){
		if(a[i].SL<=50)
			tong=tong+0;
			if(a[i].SL>50 && a[i].SL<=100)
				tong=tong+0+(a[i].SL-50)*0.05;
				if(a[i].SL>100)
					tong=tong+0+50*0.05+(a[i].SL-100)*0.10;
	}
	return tong;
}

void capnhat(char *m, int sl, HOADON a[], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(m,a[i].MaSach)==0){
			a[i].SL=a[i].SL+sl;
		}
	}
}



//------------Ham in mang ra man hinh------------
void InMang(HOADON a[], int N){
	
	int i;
	printf("\n");
	printf(" ---------------------------------------------------------------------\n");
	printf("| STT  |   Ten Sach                    | Ma Sach |So Luong | Don Gia  |\n");
	printf("|------+-------------------------------+---------+---------+----------|");
	for(i=0;i<N;i++){
		printf("\n|%4d. | %-30s| %-7s | %-6d  | %-9.1f|",
			i+1,
			a[i].TenSach,
			a[i].MaSach,
			a[i].SL,
			a[i].DG);
	}
	printf("\n ---------------------------------------------------------------------\n");
	printf("\n");
}
