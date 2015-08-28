#include<stdio.h>
#include<malloc.h>

typedef struct node* newnode;
struct node{
	int data;
	newnode next;
	};
	
void create(newnode *head,int key)
{
	newnode temp;
	temp=malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		temp->next=*head;
		*head=temp;
	}
}

void print(newnode head)
{
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
}
void search(newnode head,int k)
{
	int i=1;
	newnode first,second;
	first=second=head;
	while(second->next)
	{
		if(i<k)
		{
			second=second->next;
			i++;
		}
		else
		{
			first=first->next;
			second=second->next;	
		}
	}
	printf("kth node is %d\n",first->data);
}
int main()
{
	int i,n,k;
	newnode head=NULL;
	printf("enter the number of node\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
		create(&head,i);
	print(head);
	printf("enter the kth node to search");
	scanf("%d",&k);
	search(head,k);
}
		
