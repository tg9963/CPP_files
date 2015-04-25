#include<iostream>
#include<stdlib.h>

using namespace std;
struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

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
	s->top=-1;
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
struct tree* newnode(int data)
{
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void postorder(struct tree* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"->";	
	}
}
struct tree* peek(struct stack* s)
{
	if(isempty(s)) return NULL;
	return s->array[s->top];
}
void iterative_postorder(struct tree* root)
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
			root=NULL;
		}
	
	}while(!isempty(s));
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
	postorder(root);
	cout<<endl;
	iterative_postorder(root);
 	return 0;
}
