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
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void print_tree(struct tree* root)
{
	if(root)
	{
		cout<<root->data<<"->";
		print_tree(root->left);
		print_tree(root->right);
	}
} 
static struct tree* last_node;
void get_last_node(struct tree* root)
{
	if(root)
	{
		last_node=root;
		get_last_node(root->left);
		get_last_node(root->right);
	}
}
void delete_this(struct tree* root,struct tree* node)
{
	if(root)
	{
		get_last_node(root);
		struct tree* temp=last_node;
		if(temp!=NULL)
		{
			node->data=temp->data;
			temp->data=0;
		}
	}
}
struct tree* delete_node(struct tree* main_root,struct tree* root,int n)
{
	 
	if(root==NULL)return NULL;
	if(root->data==n)
	{
		delete_this(main_root,root);
	}
	else
	{
		delete_node(main_root,root->left,n);
		delete_node(main_root,root->right,n);
	}
	return root;
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
	print_tree(root);
	int n;
	cin>>n;
	root=delete_node(root,root,n);
	cout<<endl;
	print_tree(root);
	return 0;
}
