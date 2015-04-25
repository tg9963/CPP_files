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
		cout<<root->data<<"->";
		print_inorder(root->right);
	}
}
struct tree* lca(struct tree* root,int n1,int n2)
{
	if(root==NULL)return NULL;
	if(root->data==n1 || root->data==n2)return root;
	struct tree* left=lca(root->left,n1,n2);
	struct tree* right=lca(root->right,n1,n2);
	if(left && right )return root;
	if(left)return left;
	return right;
}
int main()	
{
	struct tree* root=newnode(10);
	root->left=newnode(9);
	root->right=newnode(8);
	root->left->right=newnode(3);
	root->left->left=newnode(15);
	root->right->left=newnode(4);
	root->right->right=newnode(2);
	print_inorder(root);
 	int n1,n2;
 	cout<<"enter n1 ";
 	cin>>n1;
 	cout<<"enter n2";
 	cin>>n2;
	root=lca(root,n1,n2);
 	cout<<endl<<root->data<<endl;
 	return 0;
}
