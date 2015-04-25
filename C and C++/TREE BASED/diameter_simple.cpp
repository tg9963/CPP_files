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
int height(struct tree* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left_height=height(root->left);
	int right_height=height(root->right);
	
	if(left_height>right_height)return left_height+1;
	return right_height+1;
}
int max(int a,int b)
{
	if(a>b)return a;
	return b;
}
int diameter(struct tree* root)
{
	if(root==NULL)
	{
		return 0;
	}
	int left_height=height(root->left);
	int right_height=height(root->right);
	
	int left_diameter=diameter(root->left);
	int right_diameter=diameter(root->right);
	
	return max(left_height+right_height+1,max(left_diameter,right_diameter));
}

int diameter_opt(struct tree* root,int *height)
{
	int left_height=0,right_height=0;
	int left_diameter=0,right_diameter=0;
	if(root==NULL)
	{
		*height=0;
		return 0;
	}
	left_diameter=diameter_opt(root->left,&left_height);
	right_diameter=diameter_opt(root->right,&right_height);
	
	*height=max(left_height,right_height)+1;
	
	return max(left_height+right_height+1,max(left_diameter,right_diameter));
}

int main()
{
struct tree* root=newnode(10);
	root->left=newnode(11);
	root->right=newnode(12);
	root->left->left=newnode(1);
	root->left->right=newnode(2);
	root->right->left=newnode(4);
	root->right->right=newnode(15);
	cout<<"Diameter 1 : "<<diameter(root)<<endl;
	int height=0;
	cout<<"Diameter 2 : "<<diameter_opt(root,&height);
	cout<<"height: "<<height;
	cout<<endl;
	return 0;
}
