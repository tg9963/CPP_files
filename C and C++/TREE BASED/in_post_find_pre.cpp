#include<iostream>
#include<stdlib.h>
using namespace std;

struct tree
{
	int data;
	struct tree* left;
	struct tree* right;
};
int finds(int in[],int data,int n)
{
	for(int i=0;i<n;i++)
	{
		if(in[i]==data)return i;
	}
	return -1;
}
void find_pre(int *in,int *post,int n)
{
	int pos=finds(in,post[n],n);
	cout<<post[n];
	if(pos!=0)
	{
		find_pre(in,post,n--);
	}
	if(pos!=n)
	{
		
	}
	
}
void print_pre(struct tree* root)
{
	if(root)
	{
		cout<<root->data<<"  ";
		print_pre(root->left);
		print_pre(root->right);
	}
}
int main()
{
	cout<<"enter n: ";
	int n,temp;
	cin>>n;
	int in[n],post[n];
	cout<<"enter inorder : ";
	for(int i=0;i<n;i++)
	{
		cin>>in[i];
	}
	cout<<"enter postorder : ";
	for(int i=0;i<n;i++)
	{
		cin>>post[i];
	}
 	find_pre(in,post,n-1);
	//print_pre(root);
	return 0;
}
