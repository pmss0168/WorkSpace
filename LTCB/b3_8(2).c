#include<stdio.h>
void main()
{
int i;
float s;
float tong=0;
printf("Moi nhap s: ");
scanf("%f",&s);
for (i=1;tong<=s;i++)
{
tong=tong+(1.0/i);
}
printf("So n do la: %d\n",i-1);
printf("Voi tong la: %0.4f",tong);

}