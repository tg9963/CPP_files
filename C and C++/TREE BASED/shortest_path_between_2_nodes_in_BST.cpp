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
struct tree* lca(struct tree* root,int n1,int n2)
{ 
	if(root==NULL)
	{
		return NULL;
	}
	if((n1<= root->data && n2>=root->data) || (n1>= root->data && n2<=root->data)) 
	{ 
		return root;
	}
	else if(n1<root->data)
	{
		return lca(root->left,n1,n2);	
	}
	else  
	{
		return lca(root->right,n1,n2);	
	}
}
void find_in_tree(struct tree* root,int n2)
{
	if(root==NULL)return ;
	cout<<root->data<<"  ";
	if(root->data==n2)
	{
		return ;
	}
	else if(root->data>n2)
	{
		return find_in_tree(root->left,n2);
	}
	else
	{
		return find_in_tree(root->right,n2);
	}
}
void shortest_path(struct tree* root,int n1,int n2)
{
 	if(root->data>n1)
	 {
	 	find_in_tree(root->left,n1);
	 	cout<<root->data<<"  ";
	 	find_in_tree(root->right,n2);
	 }
 	else 
	{
		find_in_tree(root->right,n1);
		cout<<root->data<<"  ";
		find_in_tree(root->left,n2);	
	}
}
int main()	
{
	struct tree* root=newnode(11);
	root->left=newnode(8);
	root->right=newnode(13);
	root->left->right=newnode(9);
	root->left->left=newnode(3);
	root->left->left->left=newnode(2);
	root->right->left=newnode(12);
	root->right->right=newnode(40);
	root->right->right->left=newnode(20);
	cout<<"Inorder: ";
	print_inorder(root);
	cout<<endl<<endl;
 	int n1,n2;
 	cout<<"enter n1: ";
 	cin>>n1;
 	cout<<"enter n2: ";
 	cin>>n2; 
	struct tree* lca_root=lca(root,n1,n2);
	cout<<"Shortest path between n1 and n2 : ";
	shortest_path(lca_root,n1,n2); 
 	return 0;
}
