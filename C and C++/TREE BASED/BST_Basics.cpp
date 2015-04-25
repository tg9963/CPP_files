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
struct tree* find_max(struct tree* root)
{
	if(root==NULL)
	return NULL;
	if(root->right==NULL)
	{
		cout<<"Max : "<<root->data;
		return root;
	}
	return find_max(root->right);
}

struct tree* find_min(struct tree* root)
{
	if(root==NULL)
	return NULL;
	if(root->left==NULL)
	{
		cout<<"Min : "<<root->data;
		return root;
	}
	return find_min(root->left);
}
struct tree* delete_element(struct tree* root,int data)
{
	struct tree* temp;
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data==data)
	{
		if(root->left && root->right)
		{
			temp=find_max(root->left);
			root->data=temp->data;
			root->left=delete_element(root->left,root->data);
		}
		else
		{
			temp=root;
			if(root->left==NULL)
			{
				root=root->right;
			}
			else if(root->right==NULL)
			{
				root=root->left;
			}
			free(temp);
		}
	}
	else if(root->data>data)
	{
		root->left=delete_element(root->left,data);
	}
	else
	{
		root->right=delete_element(root->right,data);
	}
	return root;
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
	cout<<"\nenter element : ";
	cin>>temp;
	root=insert(root,temp);
	cout<<endl<<endl;
	print_tree(root);
	cout<<"\nmax element : ";
	find_max(root);
	cout<<endl<<endl;
	cout<<"\nmin element : ";
	find_min(root);
	cout<<endl<<endl;
	cout<<"enter element to be deleted : ";
	cin>>temp;
	root=delete_element(root,temp);
	cout<<endl<<endl;
	print_tree(root);	
}
