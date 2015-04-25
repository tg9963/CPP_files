#include<iostream>
#include<stdlib.h>
using namespace std;

struct list
{
	int data;
	struct list* next;	
};

void split_list(struct list* head,struct list **a,struct list **b)
{
	struct list* slow;
	struct list* fast;
	if(head==NULL || head->next==NULL )
	{
		*a=head;
		*b=NULL;
	}
	else
	{ 
		 slow=head;
		 fast=head->next;
		while(fast!=NULL)
		{
			fast=fast->next;
			if(fast!=NULL)
			{
				slow=slow->next;
				fast=fast->next;
			}
		} 
		*a=head;
		*b=slow->next;
		slow->next=NULL;
	}
}

struct list* merge_lists(struct list* a,struct list* b)
{
	if(a==NULL)return b;
	if(b==NULL)return a;
	struct list* result=NULL;
	if(a->data < b->data)
	{
		result=a;
		result->next=merge_lists(a->next,b);
	}
	else
	{
		result=b;
		result->next=merge_lists(a,b->next);
	}
	return result;
}


void merge_sort(struct list** head)
{
	if(*head==NULL || (*head)->next==NULL )return ;
	struct list* a;
	struct list* b;
	struct list* head_ref=*head;
	
	split_list(head_ref,&a,&b);
	merge_sort(&a); 
	merge_sort(&b);
	*head=merge_lists(a,b); 
}


void push_list(struct list** head,int data)
{
	struct list* temp_node=(struct list*)malloc(sizeof(struct list));
	temp_node->data=data;
	temp_node->next=(*head);
	(*head)=temp_node; 
}
void print_list(struct list* head)
{
	while(head)
	{
		cout<<head->data<<"  ";
		head=head->next;
	}
}
int main()
{
	struct list* head=NULL;
	push_list(&head,10);
	push_list(&head,14);
	push_list(&head,9);
	push_list(&head,2);
	push_list(&head,4);
	push_list(&head,8);
	push_list(&head,1);
	print_list(head);
	merge_sort(&head);
	cout<<endl;
	print_list(head);
	return 0;
}
