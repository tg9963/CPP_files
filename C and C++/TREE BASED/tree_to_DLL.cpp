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
struct tree* fix_left(struct tree* root)
{
	while(root && root->left!=NULL)
	{
		root=root->left;
	}
	struct tree* temp=NULL;
	while(root && root->right!=NULL)
	{
		temp=root;
		root=root->right;
		root->left=temp;
	}
	return root;
}
struct tree* prev=NULL;
void fix_right(struct tree* root)
{
	if(root)
	{
		fix_right(root->right);
		root->right=prev;
		prev=root;
		fix_right(root->left);
	}
}
struct tree* tree_to_DLL(struct tree* root)
{
	fix_right(root);	
	return fix_left(root);
}
void print_right_root_left(struct tree* root)
{
	if(root)
	{
		print_right_root_left(root->right);
		cout<<root->data<<"->";
		print_right_root_left(root->left);
		
	}
}
void print_list(struct tree* root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->left;
	}
}

int main()	
{
	struct tree* root=newnode(10);
	root->left=newnode(9);
	root->right=newnode(8);
	root->left->right=newnode(3);
	root->left->left=newnode(1);
	root->right->left=newnode(4);
	root->right->right=newnode(2);
	print_right_root_left(root);
	root=tree_to_DLL(root);
cout<<endl;
	print_list(root);
	return 0;
}
