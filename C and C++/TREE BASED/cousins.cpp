#include<iostream>
using namespace std;

struct tree
{
	int data;
	struct tree* left,right;
};

struct tree* newnode(int data)
{
	struct tree* node=(struct tree*)malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

int find_util(struct tree* root,struct tree* parent,struct tree* a,struct tree* b,int lev)
{
	if(root==NULL)return 0;
	if(root==a || root==b)
	{
		return 1;
	}
	return ()
}


int find_cousins(struct tree* root,struct tree* a,struct tree* b)
{
	int lev=0;
  return (	find_util(root->left,root,a,b,lev+1) ||	find_util(root->right,root,a,b,lev+1) );
}


int main()
{
	struct tree* root=newnode(10);
	root->left=newnode(15);
	root->right=newnode(1);
	root->left->left=newnode(2);
	struct tree* a=root->left->left;
	root->left->right=newnode(6);
	root->right->left=newnode(4);
	root->right->right=newnode(9);
	struct tree* b=root->right->right;
	if(find_cousins(root,a,b))
	{
		cout<<"YES";
	}
	else
	{
		cout<<"NO";
	}
	return 0;
}
