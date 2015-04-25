#include<iostream>
#include<stdlib.h>
using namespace std;
struct tree
{
	char data;
	struct tree* left;
	struct tree* right;	
};
int s(char in[],int start,int end,char ch)
{
	for(int i=start;i<end;i++)
	if(in[i]==ch)return i;
	return -1;
}
static int preindex=0; 
struct tree* buildtree(char in[],char pre[],int start,int end)
{
	if(start>end)
	{
		return NULL;
	}
	
	struct tree* root=(struct tree*)malloc(sizeof(struct tree));
	root->data=pre[preindex];
//	cout<<"pre["<<preindex<<"] "<<pre[preindex]<<endl;
	preindex++;
	

	if(start==end)
	{
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	
	int index=s(in,start,end,root->data);
//	cout<<"index "<<index<<endl;
	
	if(index==-1)
	{
		root->left=NULL;
		root->right=NULL;
		return root;
	}
 
	root->left=buildtree(in,pre,start,index-1);
	root->right=buildtree(in,pre,index+1,end);

	return root;
}
void print_tree(struct tree* root)
{
	if(root==NULL)return ;
	cout<<root->data;
	print_tree(root->left);

	print_tree(root->right);
}
int main()
{
	char in[]={'D','B','E','A','F','C'};
	char pre[]={'A','B','D','E','C','F'};
	int size=sizeof(in)/sizeof(in[0]);
	struct tree* root=buildtree(in,pre,0,size);
	print_tree(root);
	return 0;
}
