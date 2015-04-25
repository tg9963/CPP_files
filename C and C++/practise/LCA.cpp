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
}
struct tree* LCA(struct tree* root,int n1,int n2)
{
	if(root==NULL)return NULL;
	if(root->data==n1 || root->data==n2)
	{
		return root;
	}
	struct tree* left=LCA(root->left,n1,n2);
	struct tree* right=LCA(root->right,n1,n2);
	
	if(left && right)return root;
	if(left)return left;
	return right;
}

int main()
{
	
	return 0;
}
