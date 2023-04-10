#include<stdio.h>
int main() {
	int n;
	printf("Chuong trinh in cac ngay trong tuan\n");
	scanf("%d",&n);
	if(n>0 && n<8){
	if(n==1){
		printf("Hom nay la Sunday");
	}else{
		if(n==2){
			printf("Hom nay la Monday");
		}else{
			if(n==3){
				printf("Hom nay la Tuesday");
			}else{
				if(n==4){
					printf("Hom nay la Wednesday");
				}else{
					if(n==5){
						printf("Hom nay la Thursday");
					}else{
						if(n==6){
							printf("Hom nay la Friday");
						}else{
							if(n==7){
								printf("Hom nay la Saturday");
							}
						}
					}
				}
			}
		}
	}
}else{
	printf("Chay lai chuong trinh va nhap lai");
}
return 0;
}