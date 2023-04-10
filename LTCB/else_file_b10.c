#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define size 100
void encrypt(char *sInput, char *sOutput){
	FILE *f1;
	FILE *f2;
	char c[size];
	char mahoa[size];	
	int n=strlen(c),i=0;
	f1=fopen(sInput,"r");
	f2=fopen(sOutput,"w");
	if(f1!=NULL){
		while(fgets(c,size,f1)!=NULL){
			if(c[n-1]=='\n')
                c[n-1]='\0';
            if(c[i]>='A'&&c[i]<='Z')
				mahoa[i]=(abs(c[i]-'A'-3))%26 +'A';
			else if(c[i]>='a'&&c[i]<='z')
				mahoa[i]=(abs(c[i]-'a'-3))%26 +'a';
				else mahoa[i]=c[i];
            i++;
		}
		fprintf(f2,"%s",mahoa);
		fclose(f1);	fclose(f2);
	}
}

int main(){
	char s1[size];
	char s2[] ="else_file_b10.txt";
	FILE *f1;
	FILE *f2;
	fgets(s1,100,stdin);
	if(s1[strlen(s1)-1]=='\n')
		s1[strlen(s1)-1]='\0';
	f1=fopen(s1,"r");
	f2=fopen(s2,"w");
	encrypt(s1,s2);
    fclose(f1);	fclose(f2);
	return 0;
}