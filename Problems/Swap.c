#include<stdio.h>

int main()
{
	int i,k;
	printf("enter two numbers\n");
	scanf("%d %d",&i,&k);
	printf("numbers before swapping   i=%d  k=%d\n",i,k);
	i=i^k;
	k=i^k;
	i=i^k;
	printf("numbers after swapping   i=%d  k=%d\n",i,k);
}
