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

int identical(struct tree* root1,struct tree* root2)
{
	if(root1==NULL && root2==NULL)return 1;
	if(root1==NULL || root2==NULL)return 0;
	return (root1->data==root2->data && identical(root1->left,root2->left) && identical(root1->right,root2->right));
}

int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(20);
	root->right=newnode(48);
	root->left->right=newnode(1);
	root->left->left=newnode(12);
	root->right->left=newnode(21);
	root->right->right=newnode(9);
	struct tree* root1=newnode(10);
	root1->left=newnode(20);
	root1->right=newnode(48);
	root1->left->right=newnode(1);
	root1->left->left=newnode(12);
	root1->right->left=newnode(21);
	root1->right->right=newnode(9);
	cout<<"Identical: "<<identical(root,root1);
	cout<<endl;
	return 0;
}
