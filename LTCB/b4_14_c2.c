#include<stdio.h>
int rev(int n, int du)
{
	if (n == 0)
		return 0;
	else
	{
		du = du*10 + n%10;
		return rev(n/10, du);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	printf("%d%d",rev(n,du));
	return 0;
}