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
	struct tree* node=(struct tree* )malloc(sizeof(struct tree));
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
	struct stack* s=(struct stack* )malloc(sizeof(struct stack));
	s->size=size;
-	s->top=-1;
	s->array=(struct tree**)malloc(s->size* sizeof(struct tree*));
	return s;
}
int isempty(struct stack* s)
{
	return (s->top==-1);
}
int isfull(struct stack* s)
{
	return (s->top==s->size);
}
void push(struct stack* s,struct tree* node)
{
	if(isfull(s))return ;
	s->top +=1;
	s->array[s->top]=node;
}
struct tree* pop(struct stack* s)
{
	if(isempty(s))
	return NULL;
	return (s->array[s->top--]);
}

struct tree* peek(struct stack* s)
{
	if(isempty(s)) return NULL;
	return s->array[s->top];
}
void delete_tree(struct tree* root)
{
	struct stack* s=create_stack(10);
	do
	{
		while(root)
		{
			if(root->right)push(s,root->right);
			push(s,root);
			root=root->left;
		}
		root=pop(s);
		if(root->right && root->right==peek(s))
		{
			pop(s);
			push(s,root);
			root=root->right;	
		}
		else
		{
			cout<<root->data<<"->";
			free(root);
			root=NULL;
		}
		
	}while(!isempty(s));
	
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
	delete_tree(root);
	return 0;
}
