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
void tree_to_dll(struct tree* root,struct tree** head)
{
	if(root==NULL)return ;
	static struct tree* prev=NULL;
	tree_to_dll(root->left,head);
	struct tree* temp;
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
	tree_to_dll(root->right,head);
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
void print_list(struct tree* head)
{
	while(head)
	{
		cout<<head->data<<"  ";
		head=head->right;
	}
}
int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(1);
	root->right=newnode(2);
	root->left->left=newnode(3);
	root->left->right=newnode(4);
	root->right->left=newnode(5);
	root->right->right=newnode(6);
	struct tree* head=NULL;
	print_tree(root);
	cout<<endl;
	tree_to_dll(root,&head);
	print_list(head);
}
