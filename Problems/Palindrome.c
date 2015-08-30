#include<stdio.h>
#include<string.h>
int count=0;
int pal(char str[],int i,int j)
{
	int k=i,q=0,l=j;
	while(i<j)
	{
		if(str[i]!=str[j])
		{
			return 0;
		}
		i++;
		j--;
	}
	for(q=k;q<=l;q++)
		printf("%c",str[q]);
	printf("\n");
	count++;
	return 0;
}
int main()
{
	int n,i,j,k,l;
	char str[10];
	printf("enter string\n");
	scanf("%s",str);
	n=strlen(str);
	
	for(i=0;i<n;i++)
	{
		k=0,l=i;
		for(j=i;j<n;j++)
		{	
			pal(str,k++,l++);
		}
	}
	printf("%d\n",count);
}
