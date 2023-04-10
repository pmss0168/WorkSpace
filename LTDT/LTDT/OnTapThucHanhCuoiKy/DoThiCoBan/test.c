#include<stdio.h>

int count_edge(int A[][50], int n){
	int count = 0, cheo = 0;
	int i, j;
	for(i = 0; i < n; i++){
		cheo = i - 1;
		for(j = 0; j < n; j++){
			if(j <= cheo){
				continue;
			}
			count += A[i][j];
		}
		cheo = 0;
	}
	return count;
}

int main(){
	int A[50][50];
	int n;
	scanf("%d", &n);
	int i, j;
	for(i = 0; i < n; i++){
		for(j = 0;j < n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	int edge = count_edge(A, n);
	int row = 1, loop, a = 0, ;
	while(row <= edge){
		lo
	}
	return 0;
}
