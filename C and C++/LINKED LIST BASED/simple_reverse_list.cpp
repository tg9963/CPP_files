#include<iostream>
#include<stdlib.h>
using namespace std;
struct list
{
	int data;
	struct list* next;
};
struct list* getlist()
{
	int n;
	cout<<"number of elements ?";
	cin>>n;
	struct list* head=(struct list*)malloc(sizeof(struct list));
	struct list* curr=head;
	for(int i=0;i<n;i++)
	{
		struct list* next_node=(struct list*)malloc(sizeof(struct list));o
		next_node->next=NULL;
		curr->next=next_node;
		curr=next_node;
	}
	return head->next;
}
void print_list(struct list* head)
{
	struct list* temp=head;
	while(temp)
	{
		cout<<temp->data<<"->";
		temp=temp->next;
	}
}
void swaps(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
struct list* reverse(struct list* head,int chunk)
{
	struct list* temp=head;
	while(temp!=NULL && temp->next!=NULL)
	{
		swaps(&temp->data,&temp->next->data);
		temp=temp->next->next;
	}
	return head;
}
void del(struct list** giv_node)

{

struct list *temp;

temp=*giv_node;

*giv_node=(*giv_node)->next;

free(temp);
}
int main()
{
	struct list* head=getlist();
	print_list(head);
	/*
	cout<<"\nenter the chunk size \n";
	int n;
	cin>>n;
	head=reverse(head,n);
	cout<<"\n";
	print_list(head);
	*/
	struct list* temp=NULL;
	del(&(temp));
	cout<<endl;
	print_list(head);
	return 0;
}
