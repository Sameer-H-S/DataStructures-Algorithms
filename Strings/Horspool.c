#include<stdio.h>
#include<string.h>
#define MAX 500
int t[MAX];
void shifttable(char p[])
{
	int i,m;
	m=strlen(p);
	for(i=0;i<MAX;i++)
		t[i]=m;
	for(i=0;i<m;i++)
		t[p[i]]=m-1-i;
}

int horspool(char src[],char p[])
{
	int n,m,i,k; 
	n=strlen(src);
	m=strlen(p);
	
	i=m-1;
	
	while(i<n)
	{
		k=0;
		while((k<m)&&(p[m-1-k]==src[i-k]))
			k++;
		if(k==m)
			return (i-m+1);
		else
			i+=t[src[i]];
	}
	return -1;
}

int main()
{
	int pos;
	char p[MAX],src[MAX];
	printf("enter the string\n");
	scanf("%s",src);
	
	printf("enter the substring\n");
	scanf("%s",p);
	
	shifttable(p);
	pos=horspool(src,p);
	
	if(pos!=-1)
		printf("strint matched pos=%d\n",pos);
	else
		printf("not matched\n");
}
