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
void print_list(struct tree* root)
{
	while(root)
	{
		cout<<root->data<<"->";
		root=root->right;
	}
}
void tree_to_DLL(struct tree* root,struct tree** head)
{
	if(root==NULL)return;
	static struct tree* prev=NULL;
	
	tree_to_DLL(root->left,head);
	if(prev==NULL)
	{
		*head=root;
	}
	else
	{
		root->left=prev; 
		prev->right=root;
	}
	prev=root;
	tree_to_DLL(root->right,head);
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
	struct tree* head=NULL;
	tree_to_DLL(root,&head);
	cout<<endl;
	print_list(head);
	return 0;
}
