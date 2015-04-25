#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
	int height;	
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	node->height=1;
	return node;
}


int height(struct tree* root)
{
	if(root==NULL)return 0;
	return root->height;
}

int getbalance(struct tree* root)
{
	if(root==NULL)return 0;
	return (height(root->left) - height(root->right));
}
int maxi(int a,int b)
{
	if(a>b)return a;
	return b;
}
struct tree* rightrotate(struct tree* root)
{
	struct tree* x=root->left;
	struct tree* y=x->right;
	
	x->right=root;
	root->left=y;
	root->height=maxi(height(root->left),height(root->right))+1;
	
	x->height=maxi(height(x->left),height(x->right))+1;
	return x;
}

struct tree* leftrotate(struct tree* root)
{
	struct tree* x=root->right;
	struct tree* y=x->left;
	x->left=root;
	root->right=y;	
	root->height=maxi(height(root->left),height(root->right))+1;
	x->height=maxi(height(x->left),height(x->right))+1; 
	return x;
	
}
struct tree* insert_into_AVL(struct tree* root,int data)
{
	if(root==NULL)
	{
		return newnode(data);
	}
	
	if(root->data==data)return root;
	
	if(root->data<data)
		root->right=insert_into_AVL(root->right,data);
	
	if(root->data>data)
		root->left=insert_into_AVL(root->left,data);
		
	root->height=maxi(height(root->left),height(root->right))+1;
	
	int balance=getbalance(root);
	
	if(balance >1 && data<root->left->data)
	{
		//left left
		return rightrotate(root);
	}
	
	if(balance <-1 && data>root->right->data)
	{
		//right right
		return leftrotate(root);
	}
	
	if(balance >1 && data<root->left->data )
	{
		//left right
		root->left=leftrotate(root->left);
		return rightrotate(root);
	}
	
	if(balance <-1 && data>root->right->data)
	{
		//right right
		root->right=rightrotate(root->right);
		return leftrotate(root);
	}
	
	return root;
}
struct tree* construct(vector<int> a,int size)
{
	struct tree* root=NULL;
	for(int i=0;i<size;i++)
	{
		//cout<<i<<" \n";
		root=insert_into_AVL(root,a[i]); 
	}
	return root;
}
void print_tree(struct tree* root)
{
	if(root)
	{
		print_tree(root->left);
		cout<<root->data<<"    ";
		print_tree(root->right);
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
}
