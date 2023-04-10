#include<stdio.h>
int main(){
	int n,i;
	float diem,tbc,max,min;
	tbc =0;
	max =-1;
	min =11;
	i =1;
	scanf("%d",&n);
	for(;i<=n;i++){
		while(i<=n){
			printf("Nhap vao diem:");
			scanf("%.1f",&diem);
			break;
		}
		tbc=(tbc+diem)/n;
		if(max<diem) max=diem;
		else if(min>diem) min=diem;
	}
	printf("TB %f Max %f Min %f",tbc,max,min);
return 0;
}