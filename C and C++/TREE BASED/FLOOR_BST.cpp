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
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
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
int floor_BST(struct tree* root,int i)
{
	if(root==NULL)return -1;
	
	if(root->data==i)return i;
	
	if(root->data>i)
	return floor_BST(root->left,i);
	
	if(root->data<i)
	{
		int floor=floor_BST(root->right,i);
		if(floor!=-1)
			return (floor>=root->data)? floor :root->data ;
		return root->data;		
	}
}
int ceil_BST(struct tree* root,int i)
{
	if(root==NULL)return -1;
	
	if(root->data==i)return root->data;
	
	if(root->data<i)
	return ceil_BST(root->right,i);
	
	if(root->data>i)
	{ 
		int ceil=ceil_BST(root->left,i); 
		if(ceil==-1)return root->data;
		if(ceil>=i)
			return ceil;
		else return root->data;
	}
}
int main()	
{
	struct tree* root=newnode(8);
	root->left = newnode(4);
    root->right = newnode(12);

    root->left->left = newnode(2);
    root->left->right = newnode(6);

    root->right->left = newnode(10);
    root->right->right = newnode(14);
	for(int i=0;i<16;i++)
	{
		cout<<i<<")    Ceil:   "<<ceil_BST(root,i)<<"    Floor: "<<floor_BST(root,i)<<endl;	
	}
	return 0;
}
