#include<iostream>
#include<stdlib.h>
#include<limits.h>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;	
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree* )malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct list
{
	struct tree* treenode;
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

void enqueue(struct queue* q,struct tree* node)
{
	struct list* listnode=(struct list*)malloc(sizeof(struct list));
	listnode->next=NULL;
	listnode->treenode=node;
	if(q->rear)q->rear->next=listnode;
	q->rear=listnode;
	if(q->front==NULL)q->front=q->rear;
}
int isempty(struct queue* q)
{
	return (q->front==NULL);
}
struct tree* dequeue(struct queue* q)
{
	if(isempty(q))return NULL;
	struct tree* temp1=q->front->treenode;
	q->front=q->front->next;
	return temp1;
}

void max_in_level(struct tree* node)
{
	struct queue* q=create_queue();
	enqueue(q,node);
	enqueue(q,NULL);
	int level=0;
	int max=INT_MAX;
	struct tree* temp;
 	while(!isempty(q))
 	{
 		temp=dequeue(q);
 		if(temp==NULL)
 		{
 			level++;
 			if(max!=INT_MAX)cout<<max<<" ";
 			cout<<endl;
 			max=INT_MAX;
 			if(!isempty(q))
			 enqueue(q,NULL);
 		}
 		else
 		{
 			if(temp->data < max)
 			max=temp->data;
 			if(temp->left)enqueue(q,temp->left);
 			if(temp->right)enqueue(q,temp->right);
 		}
 	}
}
int main()
{
	struct tree* root=newnode(1);
	root->left=newnode(28);
	root->right=newnode(4);
	root->left->left=newnode(12);
	root->left->right=newnode(9);
	root->right->left=newnode(3);
	root->right->right=newnode(6);
	max_in_level(root);
	return 0;
}
