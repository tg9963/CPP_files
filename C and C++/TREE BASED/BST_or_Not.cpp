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
		cout<<root->data<<"  ";
		print_inorder(root->right);
	}
} 

int isBST(struct tree* root)
{
	if(root==NULL)return 1;
	if(root->left && root->data<root->left->data)return 0;
	if(root->right && root->data>root->right->data)return 0;
	if(isBST(root->left) && isBST(root->right))
		return 1;
}
int main()	
{
	struct tree* root=newnode(11);
	root->left=newnode(8);
	root->right=newnode(13);
	root->left->right=newnode(9);
	root->left->left=newnode(3);
	root->left->left->left=newnode(2);
	root->right->left=newnode(12);
	root->right->right=newnode(40);
	root->right->right->left=newnode(20);
	cout<<"BST : "<<isBST(root);
 	return 0;
}
