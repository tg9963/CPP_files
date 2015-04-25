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
int root_to_leaves(struct tree* root,int sum)
{
	 if(root==NULL)return 0;
	 int subsum=sum-root->data;
	 if(root->left==NULL && root->right==NULL)
	 {
	 	if(subsum==0)
	 	{
	 		return 1;
	 	}
	 }
	 else
	 {
	 	return (root_to_leaves(root->left,subsum) || root_to_leaves(root->right,subsum));
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
	int sum=100;
	cout<<root_to_leaves(root,sum);
 	return 0;
}
