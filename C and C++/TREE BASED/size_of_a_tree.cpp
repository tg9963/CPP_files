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

int size_of_tree(struct tree* root)
{
	if(root==NULL)return 0;
	else return (size_of_tree(root->left)+1+size_of_tree(root->right));
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
	cout<<"size : "<<size_of_tree(root);
	cout<<endl;
	return 0;
}
