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
void print_inorder(struct tree* root)
{
	if(root)
	{
		print_inorder(root->left);
		cout<<root->data<<"->";
		print_inorder(root->right);
	}
}

void print_list(struct tree* root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	cout<<endl;
}
struct tree* prev=NULL;
void fix_left(struct tree* root)
{
	if(root==NULL)return ;
	fix_left(root->left);
	root->left=prev;
	prev=root;
	fix_left(root->right);
}

struct tree* fix_right(struct tree* root)
{
	while(root && root->right!=NULL)root=root->right;
	struct tree* temp=NULL;
	while(root && root->left!=NULL)
	{
		temp=root;
		root=root->left;
		root->right=temp;
	}
	return root;
}
struct tree* convert(struct tree* root)
{
	fix_left(root);
	return fix_right(root);
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
	print_inorder(root);
	cout<<endl;
	root=convert(root);
	print_list(root);
	return 0;
}
