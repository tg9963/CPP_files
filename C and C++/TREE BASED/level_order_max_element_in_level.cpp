#include<iostream>
#include<stdlib.h>
#include<limits>

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

void level_order(struct tree* root)
{
	struct queue* q=create_queue();
	enqueue(q,root);
	enqueue(q,NULL);
	int max=INT_MIN;
	while(!isempty(q))
	{
		 struct tree* temp=dequeue(q);
		 if(temp==NULL)
		 {
		 	cout<<"max in level : "<<max<<endl;
		 	max=INT_MIN;
		 	if(!isempty(q))
			 enqueue(q,NULL);
		 }
		 else
		 {
		 	if(temp->data>max)
			 max=temp->data;
		 	//cout<<temp->data<<"->";
		 	if(temp->left)enqueue(q,temp->left);
		 	if(temp->right)enqueue(q,temp->right);		 
		 }
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
	level_order(root);
	return 0;
}
