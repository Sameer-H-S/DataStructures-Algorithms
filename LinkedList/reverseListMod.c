#include<stdio.h>
#include<malloc.h>
struct node{
	int data;
	struct node *link;
};

void display(struct node *head)
{
	printf("the list is\n");
	while(head)
	{
		printf("%d\t",head->data);
		head=head->link;
	}
	printf("\n");
}

struct node * createnode(struct node *head,int key)
{
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=key;
	temp->link=NULL;
	
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	temp->link=head;
	head=temp;
	return head;
}

void rev(struct node **prev,struct node **cur,struct node **next,int mid)
{
	int count=0;
	*prev=NULL;
	while(count<mid)
	{
		*next=(*cur)->link;
		(*cur)->link=*prev;
		*prev=*cur;
		*cur=*next;
		count++;
	}
}

struct node *reverse(struct node *head)
{
	struct node *temp,*cur,*prev,*next;
	int count=0,n,mid;
	
	cur=head;
	while(cur)
	{
		cur=cur->link;
		count++;
	}
	mid=count/2;
	n=count;
	prev=NULL;
	cur=head;
	rev(&prev,&cur,&next,mid);
	if(n%2==1)
	{
		head->link=cur;
		head=prev;
		temp=cur;
		cur=cur->link;
		rev(&prev,&cur,&next,mid);
		temp->link=prev;
	}
	else
	{
		temp=prev;
		rev(&prev,&cur,&next,mid);
		head->link=prev;
		head=temp;
	}
	return head;
}


int main()
{
	int i,n,key;
	struct node * head=NULL;
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the data\n");
	for(i=0;i<n;i++)
	{
		//scanf("%d",&key);
		head=createnode(head,i);
	}
	display(head);
	head=reverse(head);
	display(head);
}
