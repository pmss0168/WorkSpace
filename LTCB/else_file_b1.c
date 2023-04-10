#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct SV{
	char *hoten;
	float li,hoa,toan;
};
int main(){
	FILE *f;
	char s[100];
	struct SV ds[100];
	char h[100];
	int n,i=0;
//	fgets(s,100,stdin);
//	n=strlen(s);
//	if(s[n-1]=='\n'){
//		s[n-1]='\0';
//	}
	f=fopen("D:\\Hoc Tap\\SourceCode\\ltcba\\else_file_indssv.txt","rt");
	fscanf(f,"%d",&n);
	if(f!=NULL){
		while(!feof(f)){
		fscanf(f,"\n");
		fscanf(f,"%[^\n]\n",&h);
		ds[i].hoten=strdup(h);
		fscanf(f,"%f %f %f",&ds[i].toan,&ds[i].li,&ds[i].hoa);
		i++;
		}
		fclose(f);
	}
	//---------------------------
	printf("Toan |Vat ly |Hoa hoc |Ho va  ten\n");
	for(i=n-1;i>=0;i--){
		printf("%5.2f|%5.2f  |%5.2f   |%s\n",ds[i].toan,ds[i].li,ds[i].hoa,ds[i].hoten);
	}
		printf("Tong: %d",n);
	
	
	return 0;
}