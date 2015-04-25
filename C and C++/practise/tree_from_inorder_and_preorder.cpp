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
int finds(int in[],int data,int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i]==data)return i;
	}
	return -1;
}
struct tree* convert(int *in,int* pre,int start,int end,int n)
{
	if(start > end)return NULL;
	static int pre_index=0;
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=pre[pre_index];
	pre_index++;
	if(start==end)
	{
		root->left=NULL;
		root->right=NULL;
		return root;	
	}
	int in_index=finds(in,root->data,n);
	if(in_index==-1)
	{
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	root->left=convert(in,pre,start,in_index-1,n);
	root->right=convert(in,pre,in_index+1,end,n);
	return root;
}
int main()
{
	cout<<"enter n ";
	int n;
	cin>>n;
	cout<<"\nenter inorder : ";
	int temp;
	int in[n],pre[n];
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	cout<<"\nenter preorder : ";
	for(int i=0;i<n;i++)
	{
		cin>>pre[i];
	}
	struct tree* root=convert(in,pre,0,n-1,n);
	cout<<endl;
	print_inorder(root);
	return 0;
}
