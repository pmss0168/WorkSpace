#include<stdio.h>
int main(){
	float th,lt,dt;
	printf("Chuong trinh in diem cua sinh vien\n");
	scanf("%f%f",&th,&lt);
	dt=(th*0.3)+(lt*0.7);
	if(dt>=8.5){
		printf("A");
	}else{
		if(dt>=7 && dt<8.5 ){
			printf("B");
		}else{
			if(dt>=5.5 && dt<7){
				printf("C");
			}else{
				if(dt>=4 && dt<5.5){
					printf("D");
				}else printf("F");
			}
		}
	}
	return 0;
}