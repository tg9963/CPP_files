#include<iostream>
#include<stdlib.h>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};
struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
struct stack
{
	int size;
	int top;
	struct tree* *array;	
};

struct stack* create_stack(int size)
{
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->size=size;
	s->top=-1;
	s->array=(struct tree**)malloc(sizeof(struct tree*));
	return s;
}
int isfull(struct stack* s)
{
	return (s->top==s->size);
}
void push(struct stack* s,struct tree* node)
{
	if(!isfull(s))
	{
	s->top+=1;
	s->array[s->top]=node;
	}
	return;
}
int isempty(struct stack* s)
{
	return (s->top==-1);
}
struct tree* pop(struct stack* s)
{
	if(isempty(s))return NULL;
	
	return (s->array[s->top--]);
} 
void print_spiral(struct tree* root)
{
	struct stack* s=create_stack(10);
	struct stack* c=create_stack(10);
	int flag=0;
	struct tree* node=NULL;
	push(s,root);
	while(!isempty(s) || !isempty(c) )
	{
		while(!isempty(s))
		{
			node=pop(s);
			
			if(node)
			{
				cout<<node->data<<"->";
				if(node->right)push(c,node->right);
				if(node->left)push(c,node->left);
			}
		}
		while(!isempty(c))
		{
			node=pop(c);
			if(node)
			{
				cout<<node->data<<"->";
				if(node->left)push(s,node->left);
				if(node->right)push(s,node->right);
			}
		}
	}
}
int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(1);
	root->right=newnode(3);
	root->left->left=newnode(6);
	root->left->right=newnode(2);
	root->right->left=newnode(4);
	root->right->right=newnode(9);
	print_spiral(root);
	return 0;
}
