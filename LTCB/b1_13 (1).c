#include<stdio.h>
#include<math.h>
int main(){
	int a,b,c;
	float cv,s,p;
	printf("--Chuong trinh tinh chu vi va dien tich tam giac--");
	scanf("%d%d%d",&a,&b,&c);
	if (a+b>c && b+c>a && c+a>b){
		cv=a+b+c;
		p=cv/2;
		s=sqrt(p*(p-a)*(p-b)*(p-c));
		printf("Chu vi cua tam giac la:%f",cv);
		printf("\nDien tich cua tam giac la:%f",s);
	}else{
		printf("Khong phai la tam giac");
	}
	return 0;
}