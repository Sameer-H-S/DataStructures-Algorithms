#include<stdio.h>

int main()
{
	int n,i,j,k; 
	
	printf("enter the n value\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		for(j=n-i;j>0;j--)
		{
			printf(" ");
		}
		k=0;
		while(k<=i)
		{
			printf("* ");
			k++;
		}
		printf("\n");
	}
}
