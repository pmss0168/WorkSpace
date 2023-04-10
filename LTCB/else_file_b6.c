#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    char s[10];
    FILE * fp;
    char a[128];
    char *tam;
    char *del;
    del=(char *)malloc(sizeof(char)*128);
    tam=(char *)malloc(sizeof(char)*128);
//    int n;
//    fgets(s,10,stdin);
//    n=strlen(s);
//    if(s[n-1]=='\n'){
//		s[n-1]='\0';
//	}
	//C:\Users\ADMIN\Desktop\sourcec.txt
    fp= fopen("D:\\Hoc Tap\\SourceCode\\ltcba\\else_file_b6.txt", "rb");
    if(fp!=NULL){
        while(fgets(a,128,fp)!=NULL){
            tam=strstr(a,"//");
            if(tam!=NULL){
            	strncpy(del,a,tam-a);
            	del[tam-a]='\0';
            	printf("%s\n",del);
            }else
            	printf("%s",a);
        }
        fclose(fp);
   	}

    return 0;
}