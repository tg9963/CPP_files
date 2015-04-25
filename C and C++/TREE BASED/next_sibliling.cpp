#include<iostream>
#include<stdlib.h>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	struct tree* sibiling;
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->sibiling=NULL;
	return node;
}
void print_inorder_sibilings(struct tree* root)
{
	if(root)
	{
		cout<<root->data<<"  ";
		if(root->sibiling)cout<<root->sibiling->data<<"  ";
		cout<<endl;
		print_inorder_sibilings(root->left);
		print_inorder_sibilings(root->right);
	}
}
void fill_sibiling(struct tree* root)
{
	if(root==NULL)
	{
		return ;
	}
	if(root->left)
		root->left->sibiling=root->right;
	if(root->right)
		root->right->sibiling=(root->sibiling)?(root->sibiling->left):NULL;
	fill_sibiling(root->left);
	fill_sibiling(root->right);
}
int main()
{
	struct tree* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	root->right->right=newnode(7);
	fill_sibiling(root);
	print_inorder_sibilings(root);
}
