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
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<"->";
		print_tree(root->right);
	}
}
static struct tree* prev=NULL; 
void fix_left(struct tree* root)
{
	if(root==NULL)return ;
	
	if(root)
	{
		fix_left(root->left);
		root->left=prev;
		prev=root;
		fix_left(root->right);
	}
	
}

struct tree* fix_right(struct tree* root)
{
	while(root && root->right!=NULL)
	{
		root=root->right;
	}
	struct tree* temp=NULL;
	while(root && root->left!=NULL)
	{
		temp=root;
		root=root->left;
		root->right=temp;
	}	
	//cout<<endl<<root->data<<endl;
	prev->right=root;
	root->left=prev;
	return root;
}
void print_list(struct tree* root)
{
	struct tree* temp=root;
	cout<<root->data<<"->";
	root=root->right;
	while(root!=temp)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
	cout<<endl;
}
struct tree* tree_to_list(struct tree* root)
{
	fix_left(root);
	return fix_right(root);
}
int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(9);
	root->right=newnode(8);
	root->left->left=newnode(1);
	root->left->right=newnode(3);
	root->right->right=newnode(2);
	root->right->left=newnode(4);
	print_tree(root);
	cout<<endl;
	struct tree* head=tree_to_list(root);
	//cout<<endl<<"hey";
	cout<<endl;
	print_list(head);
	//cout<<endl<<"hello1";
	return 0;
}
