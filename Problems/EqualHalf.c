#include<stdio.h>

void equalparts(int a[],int n)
{
	int i,j,k,fhalf=0,shalf=0,q;	
	for(i=n;i>0;i--)
	{
		if((i%2)!=1)
		{
			for(j=0;j<=n-i;j++)
			{
				fhalf=0;
				shalf=0;
				for(q=j,k=0;k<i/2;k++,q++)
				{
					fhalf=fhalf+a[q];
					shalf=shalf+a[q+i/2];
				}
				printf("fhalf=%d  shalf=%d\n",fhalf,shalf);
				
				if(fhalf==shalf)
				{
					for(q=j,k=0;k<i;k++)
					printf("%d\t",a[q++]);
					//return;
				}
				printf("\n");
			}
		}
	}
}
int main()
{
	int a[100],n,i;
	printf("enter the array length\n");
	scanf("%d",&n);
	printf("enter the array element\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	equalparts(a,n);
}
