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
	root->height=1;
	root->left=NULL;
	root->right=NULL;
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
int max(int a,int b)
{
	return a>b?a:b;
}
int height(struct tree* node)
{
	if(node==NULL)return 0;
	
	return node->height;
}
struct tree* find_max(struct tree* root)
{
	//cout<<"root: "<<root->data;
	while(root && root->right)
		root=root->right;
	return root;
}
int get_balance(struct tree* root)
{
	if(root==NULL)return 0;
	
	return (height(root->left)-height(root->right));
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
 
struct tree* delete_element(struct tree* root,int data)
{
	struct tree* max_left;
	if(root==NULL)
		return NULL;
	
	if(root->data==data)
	{
		if(root->left && root->right)
		{
			max_left=find_max(root->left);
			root->data=max_left->data;
			root->left=delete_element(root->left,root->data);
		}
		else
		{
			max_left=root;
			if(root->left==NULL)
				root=root->right;
			else if(root->right==NULL)
				root=root->left;
			free(max_left);
		}
	}
	else
	{
		if(root->data>data)
			root->left=delete_element(root->left,data);
		if(root->data<data)
			root->right=delete_element(root->right,data);
	}
	if(root==NULL)return NULL;
	root->height=max(height(root->left),height(root->right))+1;
	int balance=get_balance(root);
	
	if(balance>1 && get_balance(root->left)>=0)
		return right_rotate(root);
	if(balance<-1 && get_balance(root->right)<=0)
			return left_rotate(root);
	if(balance>1 && get_balance(root->left)<0)
	{
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}
	if(balance <-1 && get_balance(root->right)>0)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}
struct tree* insert(struct tree* root,int data)
{
	
	if(root==NULL)return newnode(data);
	//cout<<"root: "<<root->data<<endl;
	if(root->data==data)return root;
	
	if(root->data<data)
		root->right=insert(root->right,data);
	if(root->data>data)
		root->left=insert(root->left,data);
	root->height=max(height(root->left),height(root->right))+1;
	
	int balance=get_balance(root);
	/*
	if(balance>1 && data<root->left->data)
		return right_rotate(root);

	if(balance <-1 && data>root->right->data)
		return left_rotate(root);

	if(balance>1 && data>root->left->data)
	{
			root->left=left_rotate(root->left);
			return right_rotate(root);
	}

	if(balance<-1 && data<root->right->data)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}
	*/
	if(balance>1 && get_balance(root->left)>=0)
		return right_rotate(root);
	if(balance<-1 && get_balance(root->right)<=0)
			return left_rotate(root);
	if(balance>1 && get_balance(root->left)<0)
	{
		root->left=left_rotate(root->left);
		return right_rotate(root);
	}
	if(balance <-1 && get_balance(root->right)>0)
	{
		root->right=right_rotate(root->right);
		return left_rotate(root);
	}

	return root;
}

struct  tree* construct(vector<int> a)
{
	int n=a.size();
	struct tree* root=NULL;
	for(int i=0;i<n;i++)
	{
		//cout<<a[i]<<"  ";
		root=insert(root,a[i]);
		//cout<<" over "<<endl;
	}
	return root;
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
	cout<<"\n\nEnter element to be deleted: ";
	cin>>temp;
	cout<<endl<<endl;
	root=delete_element(root,temp);
	print_tree(root);
	return 0;
}
