#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MaxLength 80

typedef struct{
	char Data[MaxLength];	//Phan tu
	int n;					//So ky tu
}Line;

void appendChar(char x, Line *pL){
	if(pL->n == MaxLength){
		printf("LINE IS FULL\n");
	}
	else{
		pL->n++;
		pL->Data[pL->n-1] = x;
	}
}

int main(){
	Line L ;
	char s[MaxLength];
	char x = 'X';
	fgets(s,sizeof(s) + 1,stdin);
	if(s[strlen(s)-1] == '\n');
		s[strlen(s)-1] = '\0';
	strcpy(L.Data,s);
	appendChar(x,&L);
	printf("%s",L.Data);
	return 0;
}