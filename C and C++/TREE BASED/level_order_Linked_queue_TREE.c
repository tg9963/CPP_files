#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;	
};
struct list
{
	struct Tree *node;
	struct list *next;	
};
struct queue
{
	struct list *front;
	struct list *rear;
};
struct Tree* newnode(int data)
{
	struct Tree *temp=(struct Tree*)malloc(sizeof(struct Tree));
	temp->data=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
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
void enqueue(struct queue* q,struct Tree * node)
{
//	printf("hey\n");
	struct list* listnode=(struct list*)malloc(sizeof(struct list));
	listnode->node=node;
	listnode->next=NULL;
	if(q->rear!=NULL)q->rear->next=listnode;
	q->rear=listnode;
	if(q->front==NULL)
	{
		q->front=q->rear;
	}
}
struct Tree* dequeue(struct queue* q)
{
//	if(isempty(q))return NULL;
	struct Tree* temp;
	struct list* temp2;
	temp=q->front->node;
	temp2=q->front;
	q->front=q->front->next;
	free(temp2);
	return temp;
}
void levelorder(struct Tree* root)
{
	struct Tree* temp;
	struct queue *q=create_queue();
	enqueue(q,root);
	while(!isempty(q))
	{
		temp=dequeue(q);
		printf("%d -> ",temp->data);
			if(temp->left)enqueue(q,temp->left);
			if(temp->right)enqueue(q,temp->right);	
	}
//	return level;
}
int main()
{
	struct Tree* root=newnode(10);
	root->left=newnode(20);
	root->right=newnode(30);
	root->left->left=newnode(25);
	root->left->right=newnode(27);
	root->right->left=newnode(25);
	root->right->right=newnode(50);
	 levelorder(root);
	return 0;
}

