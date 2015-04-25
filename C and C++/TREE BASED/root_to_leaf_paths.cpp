#include<iostream>
#include<stdlib.h>
#define MAX_LEN 10
using namespace std;
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;	
};
struct list
{
	struct tree* node;
	struct list* next;
};
struct queue
{
 	struct list* front;
	struct list* rear;
};

struct queue* create_queue()
{
 	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
 	q->front=NULL;
 	q->rear=NULL;
 	return q;
}
int isempty(struct queue* q)
{
	return (q->front==NULL);
}
void enqueue(struct queue* q,struct tree* node)
{
	 struct list* listnode=(struct list* )malloc(sizeof(struct list));
	 listnode->node=node;
	 listnode->next=NULL;
	 if(q->rear!=NULL)q->rear->next=listnode;
	 q->rear=listnode;
	 if(q->front==NULL)q->front=q->rear;
}

struct tree* dequeue(struct queue* q)
{
	if(isempty(q)) return NULL;
	struct list* temp=q->front;
 	struct tree* temp1=q->front->node;
	q->front=q->front->next;
	free(temp);
	return temp1;
}


struct tree* newnode(int data)
{
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void print_path(int arr[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<arr[i]<<"->";
	}
	cout<<endl;
}
void root_to_leaves(struct tree* root,int path[],int length)
{
	if(root==NULL)return ;
	path[length]=root->data;
	length++;
	if(root->left==NULL && root->right==NULL)
	{
		print_path(path,length);
	}
	else
	{
		 root_to_leaves(root->left,path,length);
		 root_to_leaves(root->right,path,length);
	}
}
 
int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(20);
	root->right=newnode(48);
	root->left->right=newnode(11);
	root->left->left=newnode(12);
	root->right->left=newnode(21);
	root->right->right=newnode(9);
	int path[MAX_LEN];
	int length=0;
	root_to_leaves(root,path,length);
 	return 0;
}
