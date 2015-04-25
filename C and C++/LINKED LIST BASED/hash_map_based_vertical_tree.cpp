#include<iostream>
#include<stdlib.h>
#include<map>
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
	struct tree* node=(struct tree* )malloc(sizeof(struct tree));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}

void get_vertical(struct tree* root,int hd, map<int,vector<int> > &m)
{
	if(root==NULL)return ;
	m[hd].push_back(root->data);
	get_vertical(root->left,hd-1,m);
	get_vertical(root->right,hd+1,m);
}

void print_vertical(struct tree* root)
{
	if(root==NULL)return ;
	
	map<int,vector<int> > m;
	int hd=0;
	get_vertical(root,hd,m);
	
	map<int,vector<int> >::iterator it;
	for(it=m.begin();it!=m.end();it++)
	{
		for(int i=0;i<it->second.size();i++)
		{
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
	
}


int main()
{
	struct tree* root;
	root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->right=newnode(7);
	root->right->left=newnode(6);
	print_vertical(root);
	return 0;
}
