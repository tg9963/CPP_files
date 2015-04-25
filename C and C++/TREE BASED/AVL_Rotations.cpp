#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
struct tree
{
	int data;
	int height;
	struct tree* left;
	struct tree* right;
};

struct tree* newnode(int data)
{
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=data;
	root->height=0;
	root->left=NULL;
	root->right=NULL;
	return root;
}

int height(struct tree* root)
{
	if(root==NULL)return 0;
	return root->height;
}
int get_balance(struct tree* root)
{
	if(root==NULL)return 0;
	
	return (height(root->left)-height(root->right));
}
int max(int a,int b)
{
	return a>b?a:b;
}
struct tree* left_rotate(struct tree* root)
{
	struct tree* x=root->right;
	struct tree* y=x->left;
	
	x->left=root;
	root->right=y;
	
	root->height=max(height(root->left),height(root->right))+1;
	
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
struct tree* right_rotate(struct tree* root)
{
	struct tree* x=root->left;
	struct tree* y=x->right;
	
	x->right=root;
	root->left=y;
	
	root->height=max(height(root->left),height(root->right))+1;
	
	x->height=max(height(x->left),height(x->right))+1;
	
	return x;
}
struct tree* insert_AVL(struct tree* root,int data)
{
	if(root==NULL)return newnode(data);
	
	if(root->data==data)return root;
	
	if(root->data > data )
		root->left=insert_AVL(root->left,data);
	if(root->data < data)
		root->right=insert_AVL(root->right,data);
	
	root->height=max(height(root->left),height(root->right))+1;
	int balance=get_balance(root);
	
	if(balance >1 && data<root->left->data)
	{
		return right_rotate(root);
	}
	
	if(balance<-1 && data>root->right->data)
	{
		return left_rotate(root);
	}
	
	if(balance >1 && data>root->left->data)
	{
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}
	if(balance <-1 && data<root->right->data)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}
	
	return root;
}
struct tree* construct(vector<int> a)
{
	int size=a.size();
	struct tree* root=NULL;
	for(int i=0;i<size;i++)
	{
		//cout<<i<<" \n";
		root=insert_AVL(root,a[i]);
	}
	return root;
}
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<"  ";
		print_tree(root->right);
	}
}
int main()
{
	vector<int> a;
	int temp,n;
	cout<<"enter n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>temp;
		a.push_back(temp);
	}
	struct tree* root=construct(a);
	print_tree(root);
	return 0;
}
