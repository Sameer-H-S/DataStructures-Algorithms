#include<stdio.h>

int main()
{
	int n,res;
	printf("enter the number\n");
	scanf("%d",&n);
	
	if(n>5)
	{
		res=(n/2)*(n-n/2-1);
		printf("max A are %d\n",res);
	}
	else
		printf("%d\n",n);
return;
}
