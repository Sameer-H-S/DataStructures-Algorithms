#include<stdio.h>

void merge(int b[],int c[],int a[],int p,int q)
{
	int k=0,i=0,j=0;
	while((i<p)&&(j<q))
	{
		if(b[i]<c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<p)
	{
		a[k++]=b[i++];
	}
	while(j<p)
	{
		a[k++]=b[j++];
	}
return;
}

void mergesort(int a[10],int n)
{
	int b[10],c[10],i,j,p=0,q=0;
	if(n>1)
	{
		for(i=0;i<n/2;i++)
		{
			b[i]=a[i];
		}
		p=i;
		for(j=0,i=n/2;i<n;i++,j++)
		{
			c[j]=a[i];
		}
		q=j;
		mergesort(b,p);
		mergesort(c,q);
		merge(b,c,a,p,q);
	}
	return;
}
int main()
{
	int n,a[10],i;
	printf("enter the size\n");
	scanf("%d",&n);
	printf("enter the array elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	mergesort(a,n);
	printf("sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}


	
