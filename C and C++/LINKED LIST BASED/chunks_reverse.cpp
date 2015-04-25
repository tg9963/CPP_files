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
		struct list* next_node=(struct list*)malloc(sizeof(struct list));
		cin>>next_node->data;
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

struct list* reverse(struct list* head,int chunk)
{
	struct list* prev=NULL;
	struct list* next;
	struct list* curr=head;
	int count=0; 
	while(curr !=NULL && count<chunk)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL)
	{
		head->next=reverse(next,chunk);
	}
	return prev;
}
int main()
{
	struct list* head=getlist();
	print_list(head);
	cout<<"\nenter the chunk size \n";
	int n;
	cin>>n;
	head=reverse(head,n);
	cout<<"\n";
	print_list(head);
	return 0;
}
