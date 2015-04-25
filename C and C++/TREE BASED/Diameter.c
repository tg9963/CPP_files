#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree* newnode(int data)
{
	struct Tree* root=(struct Tree*)malloc(sizeof(struct Tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
int maxi(int a,int b)
{
 	return (a>b?a:b);
}

int diameter(struct Tree* root,int *p)
{
	if(root==NULL)return 0;
	int left,right;
	left=diameter(root->left,p);
	right=diameter(root->right,p);
	if(left+right > *p)*p=left+right;
	return maxi(left,right)+1 ;
}
int main()
{
	struct Tree* root=newnode(10);
	root->left=newnode(11);
	root->right=newnode(12);
	root->left->left=newnode(1);
	root->left->right=newnode(2);
	root->right->left=newnode(4);
	root->right->right=newnode(15);
	int a=0;
	int *p;
	p=&a;
	printf("%d",diameter(root,p));
	return 0;
}
