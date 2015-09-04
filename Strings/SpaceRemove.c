#include<stdio.h>
#include<string.h>
int main()
{
	char str[100];
	int count=0,i,n;
	printf("enter the string\n");
	//scanf("%s",str);   ->scanf doesn't accept space 
	//scanf("%[^\n]s",str);  ->this works
	gets(str);
	n=strlen(str);
	for(i=0;str[i];i++)
		if(str[i]!=' ')
			str[count++]=str[i];
	str[count]='\0';
	printf("string after removing spaces\n");
	puts(str);
}
