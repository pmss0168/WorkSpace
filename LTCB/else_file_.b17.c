#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
struct PhanSo{
	int TuSo,MauSo;
};
//UCLN
int gcd(int a, int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
//BCNN
int lcd(int a, int b){ 
	return (fabs(a*b))/gcd(a,b);
}

int main(){
	struct PhanSo a,b,c;
//	char s[100];
	FILE *f;
//	fgets(s,100,stdin);
//	if(s[strlen(s)-1]=='\n')
//		s[strlen(s)-1]='\0';
	f=fopen("D:\\Hoc Tap\\SourceCode\\ltcba\\else_file_b17.txt","r");
	fscanf(f,"%d/%d%*c%d/%d",&a.TuSo,&a.MauSo,&b.TuSo,&b.MauSo);
	fclose(f);
	int tempa,tempb;
	//tam = tuso x BCNN : mauso
	tempa=(a.TuSo*(lcd(a.MauSo,b.MauSo)/a.MauSo));
	tempb=(b.TuSo*(lcd(a.MauSo,b.MauSo)/b.MauSo));
	c.TuSo=tempa+tempb;
	c.MauSo=lcd(a.MauSo,b.MauSo);
	printf("%d/%d + %d/%d = %d/%d",a.TuSo,a.MauSo,b.TuSo,b.MauSo,c.TuSo,c.MauSo);
	return 0;
}