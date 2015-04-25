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
	struct stack* s=(struct stack*)malloc(sizeof(struct stack));
	s->size=size;
	s->top=-1;
	s->array=(struct tree** )malloc(s->size * sizeof(struct tree*));
	return s;
}
int isfull(struct stack* s)
{
return (s->top==s->size);
}
int isempty(struct stack* s)
{
	return (s->top==-1);
}
void push(struct stack* s,struct tree* node )
{
	if(isfull(s))
	{
		cout<<"stack full \n";
		return ;
	}
	else
	{
		s->top+=1;
		s->array[s->top]=node;
	}
}
struct tree* pop(struct stack* s)
{
	if(isempty(s))
	{
		cout<<"stack empty \n";
		return NULL;
	}
	else
	{
		return (s->array[s->top--]);
	}
}
struct tree* inorder(struct tree* root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d->",root->data);
		inorder(root->right);
	}
}

void iterative_inorder(struct tree* root)
{
	struct stack* s=create_stack(10);
	while(1)
	{
		while(root)
		{
		 	push(s,root);
			root=root->left;
		} 
		if(isempty(s))break;
		root=pop(s); 
		cout<<root->data<<"->";
		root=root->right;
	}
}
struct tree* newnode(int data)
{
	struct tree* root=(struct tree* )malloc(sizeof(struct tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
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
	inorder(root);
	cout<<endl;
	iterative_inorder(root);
	return 0;
}
