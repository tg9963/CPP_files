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
 
void swaps(struct tree* left,struct tree* right)
{
	struct tree* temp=left;
	left=right;
	right=temp;
}
struct tree* mirror(struct tree* root)
{
	if(root==NULL)return NULL ;
	mirror(root->left);
	mirror(root->right);
	struct tree* temp=root->left;
	root->left=root->right;
	root->right=temp;
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
int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(20);
	root->right=newnode(48);
	root->left->right=newnode(11);
	root->left->left=newnode(12);
	root->right->left=newnode(21);
	root->right->right=newnode(9);
	root=mirror(root);
	print_tree(root);
	cout<<endl;
	return 0;
}
