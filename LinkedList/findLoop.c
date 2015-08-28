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

void display(newnode head)
{
	printf("the list is\n");
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
} 

void checkloop(newnode head)
{
	newnode slow,fast;
	slow=head;
	fast=head;
	while(fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
		if(fast==slow)
		{
			printf("loop\n");
			return;
		}
	}
	printf("no loop\n");
	return;
}
			
int main()
{
	int i,n;
	newnode head=NULL;
	printf("enter the number of node\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		/*printf("enter the value\n");
		scanf("%d",&key);*/
		create(&head,i);
	}
	display(head);
	head->next->next->next=head;
	checkloop(head);	
}
