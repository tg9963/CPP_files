#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree* newnode(int data)
{
	struct Tree* p=(struct Tree*)malloc(sizeof(struct Tree));
	p->data=data;
	p->left=NULL;
	p->right=NULL;
	return p;
}
void print_tree(struct Tree* root)
{
	if(root==NULL)return ;
	cout<<root->data<<endl;
	print_tree(root->left);
	print_tree(root->right);
}
int find_index(int in[],int data,int *n)
{
	int index=0;
	for(int i=0;i<*n;i++)
	{
		if(in[i]==data)return i;
	}
	return -1;
}
int get_keys(int *l,int *r,int in[],int index,int *n)
{
	int j=0;
	for(int i=0;i<index;i++)l[j++]=in[i];
	j=0;
	for(int i=index+1;i<*n;i++)r[j++]=in[i];
	return j;
}
struct Tree* construct_tree(int in[],int level[],int start,int end,int *n,struct Tree* root)
{
	if(start>end)return NULL;
	int *l=new int[*n];
	int *r=new int[*n];
	int index=find_index(in,level[0],*n);
	int r_size=get_keys(l,r,in,index,*n);
	int l_size=*n-r_size;
	for(int i=0;i<r_size;i++)
}
void construct(int in[],int level[],int n)
{
	struct Tree* root=newnode(level[0]);
	construct_tree(in,level,0,n-1,&n,root);
	print_tree(root);
}
int main()
{
	int n;
	cin>>n; 
	int in[n];
	int level[n];
	for(int i=0;i<n;i++)cin>>in[i];
	for(int i=0;i<n;i++)cin>>level[i];
	construct(in,level,n);
}
