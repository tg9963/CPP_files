#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
	int data;
	struct list* next;
};


struct list* head=NULL;
struct list* curr=NULL;

struct list* newnode(int data)
{
	struct list* node=(struct list*)malloc(sizeof(struct list));
	node->data=data;
	node->next=NULL;
	return node;
}
struct list* get_list(struct list** head,int n)
{
	int data;
	cin>>data;
	struct list* node=newnode(data);
	(*head)=node;
	curr=*head;
	int num=n;
	num--;
	if(num>0)
	{
		(*head)->next=get_list(&(*head)->next,num);
		
	}
	return *head;
}
void pop_front(struct list** head)
{
	if(head==NULL)
		return;
	
	struct list* temp=*head;
	*head=(*head)->next;
	
	free(temp);
	
}
void push_front(struct list** head)
{
	cout<<"\nData: ";
	int data;
	cin>>data;
	if(*head==NULL)
	{
		
	*head= newnode(data);
	}
	struct list* temp=newnode(data);
	temp->next=*head;
	*head=temp;
}
void push_back(struct list** head)
{
	cout<<"\nData: ";
	int data;
	cin>>data;
	if(*head ==NULL)
	{
	*head= newnode(data);
	return ;
	}
	struct list* temp=*head;
	struct list* prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if(prev==NULL)
	{
		(*head)->next=newnode(data);	
		return ;
	} 
	else 
	{
		 temp->next=newnode(data);
	}
}

void pop_back(struct list** head)
{
	if(*head==NULL)return ;
	struct list* temp=*head;
	struct list* prev=NULL;
	while(temp->next!=NULL)
	{
		prev=temp;
		temp=temp->next;
	}
	if(prev==NULL)
	{
		*head=NULL;	
	} 
	else 
	{
		prev->next=temp->next;
		free(temp);
	}
}
void print_list(struct list* head)
{
	while(head!=NULL)
	{
		cout<<head->data<<"  ";
		head=head->next;
	}
}
int main()
{
	int n;
	cout<<"\nSIZE ? :";
	cin>>n;
	head=get_list(&head,n);
	cout<<endl;
	cout<<"list: ";
	print_list(head);
	cout<<"\npush_back : \n";
	push_back(&head);
	cout<<endl;
	print_list(head);
	cout<<"\npush_front : \n";
	push_front(&head);
	cout<<endl;
	print_list(head);
	cout<<"\npop_front : \n";
	pop_front(&head);
	cout<<endl;
	print_list(head);
	cout<<endl;
	cout<<"\npop_back : \n";
	pop_back(&head);
	cout<<endl;
	print_list(head);
	return 0;
}

