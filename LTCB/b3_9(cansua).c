#include<stdio.h>
int main(){
	int nto,i,tong;
	float tbc;
	tong=0;
	tbc=0;
	scanf("%d",nto);
	do{
		if(nto%i==0) i++;		
	}while(i<=nto);
	for(i=1;i<nto;i++){
		if(i%2==0) tong=tong+i;
		else tbc=(tbc+i)/nto;
		
	}
	printf("Tong so chan la: %d",tong);
	printf("TBC cac so le la: %.2d",tbc);
return 0;
}