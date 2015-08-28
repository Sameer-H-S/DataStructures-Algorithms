#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node* newnode;
struct node{
	int data;
	newnode next;
	};

void create(newnode *head,int key)
{
	newnode temp;
	temp=(newnode)malloc(sizeof(struct node));
	temp->data=key;
	temp->next=NULL;
	if(*head==NULL)
		*head=temp;
	else
	{
		temp->next=*head;
		*head=temp;
	}
	return;
}
		
void print(newnode head)
{
	while(head)
	{
		printf("%d\t",head->data);
		head=head->next;
	}
	printf("\n");
	return;
}

newnode swap(newnode head,int k)
{
	int i=1;
	newnode perent1,temp,perent2,fix,first,second;
	perent1=perent2=NULL;
	fix=first=second=head;
	
	while(second->next)
	{
		if(i<k)
		{
			i++;
			perent1=fix;
			fix=fix->next;
			second=second->next;
		}
		else
		{
			second=second->next;
			perent2=first;
			first=first->next;
		}
	}
	
	if(fix==first)
		return head;
	else if(fix==head)
		{
			first->next=fix->next;
			perent2->next=fix;
			fix->next=NULL;
			return first;
		}
	else if(first==head)
		{
			fix->next=first->next;
			perent1->next=first;
			first->next=NULL;
			return fix;
		}
	else if(fix->next==first)
		{
			perent1->next=first;
			temp=first->next;
			first->next=fix;
			fix->next=temp;
		}
	else if(first->next==fix)
		{
			perent2->next=fix;
			temp=fix->next;
			fix->next=first;
			first->next=temp;
		}
	else
		{
			perent1->next=first;
			temp=first->next;
			first->next=fix->next;
			perent2->next=fix;
			fix->next=temp;
		}
		return head;
}
			

int main()
{
	int i,n,k;
	newnode head=NULL;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		create(&head,i);
	}
	printf("the list is\n");
	print(head);
	
	for(;;)
	{
		
		printf("enter the kth value OR 0 to exit\n");
		scanf("%d",&k);
		if(k==0)
			exit(0);
		head=swap(head,k);
		print(head);
	}
		
}
