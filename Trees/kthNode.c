#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node* newnode;
struct node{
	int data;
	newnode llink,rlink;
	};
newnode getnode(newnode head,int key)
{
	newnode perent;
	 while(head)
	{
	if(key==head->data)
	{
		printf("invalid data\n");
		exit(0);	
	}
	perent=head;
		if(key<head->data)
			head=head->llink;
		else
			head=head->rlink;
	}
	return perent;
}

void bst(newnode *head,int key)
{
	newnode temp,perent;
	temp=malloc(sizeof(struct node));
	temp->data=key;
	temp->llink=temp->rlink=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		
		perent=getnode(*head,key);	
		if(key<perent->data)
			perent->llink=temp;
		else
			perent->rlink=temp;
	}
}		

void print(newnode head)
{
	if(head)
	{
		print(head->llink);
		printf("%d\t",head->data);
		print(head->rlink);
	}
	return;
}

void search(newnode head,int k)
{
	static int i=0; 
	if(head)
	{
		search(head->llink,k);
		i++;
		if(i==k)
		{
			printf("the value is %d\n",head->data);
			return;
		}
		search(head->rlink,k);	
	}
	return ;
}
		
int main()
{
	int i,key,n,k;
	newnode head=NULL;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&key);
		bst(&head,key);
	}
	printf("tree\n");
	print(head);
	printf("\n");
	printf("enter kth vaue\n");
	scanf("%d",&k);
	search(head,k);
}
		
	
