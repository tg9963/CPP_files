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
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

struct tree* construct_BST(struct tree* root,int data)
{
	if(root==NULL)
	{
 		return newnode(data);
	}
	if(data==root->data)return root;
	else if(data>root->data)
	{
			root->right=construct_BST(root->right,data);
	}
	else if(data<root->data)
	{
		root->left=construct_BST(root->left,data);
	}
	return root;
}
struct tree* insert(struct tree* root,int data)
{
	return construct_BST(root,data);
}
struct tree* construct(vector<int> a,int n)
{
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	struct tree* temp_root=root;
	root->data=a[0];
	root->left=NULL;
	root->right=NULL;
	for(int i=1;i<n;i++)
	{
		root=construct_BST(root,a[i]);	
	}
	return root;
}
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<" ";
		print_tree(root->right);
	}
}

int i=1;
int find_kth(struct tree* root,int k)
{	 
	if(root)
	{
	
		find_kth(root->left,k);
		if(i==k)
		{
			return root->data;
		}
		find_kth(root->right,k);
	}
}
 
int main()
{
	int temp,n;
	cout<<"enter n : ";
	cin>>n;
	cout<<"\nenter elements : ";
	vector<int> a;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	struct tree* root=construct(a,n);
	cout<<endl<<endl;
	print_tree(root);
	cout<<endl<<endl;
	cout<<"\nenter k : ";
	cin>>temp;
 	cout<<find_kth(root,temp);	
}
