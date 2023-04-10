/* 
   Ho va ten : PHAM MINH SANG
   MSSV      : B2110976
   So may    : 27
   De so     : ...          
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


//--------------Phan khai bao prototype cua sinh vien ---------
void docfile(char *filename, HOADON a[], int *n);
void InMang(HOADON a[], int N);
int tong(HOADON a[], int n);
void sapxep(HOADON a[],int n);
void capnhat(char *ms, int SL, HOADON a[], int n);

// Chuong trinh chinh
int main() { 
	FILE *f;   
	HOADON hd[ML],x;	
	int N=0,i=0;
	char ms[15];
	int sl;	
	puts("--------KIEM TRA THUC HANH C-LAN 1--------");
	docfile("input1.txt",hd,&N);
	InMang(hd,N);
	strcpy(x.MaSach,"CT101");
	strcpy(x.TenSach,"Lap trinh can ban C");
	x.SL=100;
	x.DG=50;
	hd[N]=x;
	N++;
	InMang(hd,N);
	printf("\nTong tien phai tra la: %d\n",tong(hd,N));
	printf("\nNhap ma sach canh cap nhat:");
	fgets(ms,15,stdin);
	if(ms[strlen(ms)-1]=='\n')
		ms[strlen(ms)-1]='\0';
	printf("Nhap so luong can cap nhat:");
	scanf("%d",&sl);
	capnhat(ms,sl,hd,N);
	InMang(hd,N);
	sapxep(hd,N);
	InMang(hd,N);
	return 0;
}



//---------Phan cai dat ham cua sinh vien---------------
void docfile(char *filename, HOADON a[], int *n){
	FILE *f;
	int i=0;
	f=fopen(filename,"r"); 	//Dau vao input1.txt
	if(f!=NULL){
		while(!feof(f)){
			fscanf(f,"%[^\t]\t%[^\t]\t%d%f%*c",
			a[i].MaSach,
			a[i].TenSach,
			&a[i].SL,
			&a[i].DG);
			i++;
		}
	}
	*n=i;
	fclose(f);
}

int tong(HOADON a[], int n){
	int i,tong=0;
	for(i=0;i<n;i++){
		tong=tong+a[i].SL*a[i].DG;
	}
	return tong;
}

void sapxep(HOADON a[],int n){
	int i,j;
	HOADON temp;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++){
			if(a[i].SL>a[j].SL){
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
}

void capnhat(char *ms, int sl, HOADON a[], int n){
	int i;
	for(i=0;i<n;i++){
		if(strcmp(a[i].MaSach,ms)==0){
			a[i].SL=a[i].SL+sl;
			break;
		}
	}
}




//------Phan cai dat da cho-------------
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
	
