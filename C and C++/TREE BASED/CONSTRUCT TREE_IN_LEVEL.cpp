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
int find_index(int in[],int data,int n)
{
	int index=0;
	for(int i=0;i<n;i++)
	{
		if(in[i]==data)return i;
	}
	return -1;
}
void clear(int left[],int right[],int n)
{
	for(int i=0;i<n;i++)left[i]=-1;
	for(int i=0;i<n;i++)right[i]=-1;
}
void add_elements(int left[],int right[],int in_index,int in[],int n,int *p,int *q)
{	
clear(left,right,n);
	cout<<"in add elements 2 \n";
	in[in_index]=-1;
	int count=0;
	for(int i=0;i<in_index;i++)
	{
		if(in[i]!=-1)left[count++]=in[i];
	}
		cout<<"in add elements 3 \n";
	*p=count;
	count=0;
	for(int i=in_index;i<n;i++)
	{
		if(in[i]!=-1)right[count++]=in[i];
	}
	*q=count;
	count=0;
		cout<<"in add elements 4"<<" p "<<*p<<" q "<<*q <<endl;
	//return count;
}
void construct_tree(int in[],int level[],int index,int left[],int right[],int n,struct Tree* root)
{
	if(n==0)return ;
	int p,q;
	int in_index=find_index(in,level[index],n);
	cout<<"\n INDEX "<<in_index<<" level[index] "<<level[index]<<endl;
	if(in_index==-1)
		{
			return ;
		}
	add_elements(left,right,in_index,in,n,&p,&q);
	cout<<endl<<"LEFT \n";
	for(int i=0;i<p;i++)cout<<left[i]<<endl;
	cout<<endl<<"right \n";
	for(int i=0;i<q;i++)cout<<right[i]<<endl;
	cout<<"\n p "<<p<<" q "<<q;
	if(p==1 && q==1)
	{
		if(left[0] !=-1)
		{
		struct Tree* temp=newnode(left[0]); 
		root->left=temp;
		}
		if(right[0]!=-1)
		{
		struct Tree* temp1=newnode(right[0]); 
		root->right=temp1;
		}
		return ;
	}
	if(p==1)
	{
		struct Tree* temp=newnode(left[0]); 
		root->left=temp;
		level[find_index(level,left[0],n)]=-1;
		construct_tree(in,level,find_index(level,right[0],p),left,right,n,root->right);
		return ;
	}
	if(q==1)
	{
		struct Tree* temp=newnode(right[0]); 
		root->right=temp;
		level[find_index(level,right[0],n)]=-1;
		//level[find_index(level,right[0],n)]=-1;	
		construct_tree(in,level,find_index(level,left[0],q),left,right,n,root->left);
		return ;
	}
	construct_tree(in,level,find_index(level,left[0],q),left,right,n,root);
	construct_tree(in,level,find_index(level,right[0],p),left,right,n,root);
	//	get_subtree(in,level,find_index(level,left[0],p),left,right,n,root);	
	//	get_subtree(in,level,find_index(level,right[0],q),left,right,n,root);
}
void print_tree(struct Tree* root)
{
	if(root==NULL)return ;
	cout<<root->data<<endl;
	print_tree(root->left);
	print_tree(root->right);
}
void construct(int in[],int level[],int n)
{
	if(n<=0)return ;
	int left[n],right[n];
	struct Tree* root=newnode(level[0]);
	level[0]=-1;
	construct_tree(in,level,0,left,right,n,root);
	cout<<"TREE \n \n \n";
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
	cout<<"\n \n \n  IN  \n \n \n";
	for(int i=0;i<n;i++)cout<<in[i]<<endl;
	return 0;
}
