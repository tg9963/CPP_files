#include<iostream>
#include<stdlib.h>
#include<vector>
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

struct tree* construct_BST(struct tree* root,int data)
{
	if(root==NULL)
	{
 		return newnode(data);
	}
	if(data==root->data)return root;
	else if(data>root->data)
	{
			root->right=construct_BST(root->right,data);
	}
	else if(data<root->data)
	{
		root->left=construct_BST(root->left,data);
	}
	return root;
} 
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<" ";
		print_tree(root->right);
	}
}
void join(struct tree* node1,struct tree* node2)
{
	if(node2)
	{
		join(node1,node2->left);
		construct_BST(node1,node2->data);
		join(node1,node2->right);
	}
}
int main()
{ 
	struct tree* root1=newnode(11);
	root1->left=newnode(8);
	root1->right=newnode(13);
	root1->left->right=newnode(9);
	root1->left->left=newnode(3);
	root1->left->left->left=newnode(2);
	root1->right->left=newnode(12);
	root1->right->right=newnode(40);
	root1->right->right->left=newnode(20);
	struct tree* root2=newnode(12);
	root2->left=newnode(8);
	root2->right=newnode(14);
	root2->left->right=newnode(10);
	root2->left->left=newnode(2); 
	root2->right->left=newnode(13);
	root2->right->right=newnode(15);
	print_tree(root1);
	cout<<endl<<endl;
	join(root1,root2);
	print_tree(root1);
}
