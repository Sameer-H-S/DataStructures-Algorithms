#include<stdio.h>

int main()
{
	int item,a[100],i,j,n;
	printf("enter the number of element\n");
	scanf("%d",&n);
	printf("enter the element\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		
	for(i=1;i<n;i++)
	{
		item=a[i];
		for(j=i-1;j>=0&&a[j]>item;j--)
			a[j+1]=a[j];
		a[j+1]=item;	
	}
	
	printf("sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
