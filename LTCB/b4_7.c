#include<stdio.h>
char LowCase(char ch){
	char t;
	t=ch-32;
	return t;
}
int main(){
	char c;
	scanf("%c",&c);
	printf("%c",LowCase(c));
	return 0;
}