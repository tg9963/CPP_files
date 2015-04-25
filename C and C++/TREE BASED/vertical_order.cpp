#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree* )malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void get_min_max(struct tree* root,int *min,int *max,int hd)
{
	if(root==NULL)
	return ;
	if(hd < *min)
	{
		*min=hd;
	}
	else if(hd > *max)
	{
		*max=hd;
	}
	get_min_max(root->right,min,max,hd-1);
	get_min_max(root->right,min,max,hd+1);
}
int temp=0;
int print_(struct tree* root,int line_no,int hd)
{
	if(root==NULL)
	return temp;
	if(hd==line_no)
	{
		temp+=root->data;
		cout<<root->data<<" ";
	}
	print_(root->left,line_no,hd-1);
	print_(root->right,line_no,hd+1);
}

void print_vertical(struct tree* root)
{
	if(root==NULL)
	return ;
	int min=0,max=0;
	get_min_max(root,&min,&max,0);
	//cout<<min<<" "<<max<<endl;
	for(int i=min;i<=max;i++)
	{
		cout<<print_(root,i,0)<<endl;
		temp=0;
		cout<<endl;
	}
	
}


int main()
{
	struct tree* root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	print_vertical(root);
	return 0;
}
