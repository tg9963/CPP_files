#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};
struct Tree* newnode(int data)
{
	struct Tree* root=(struct Tree*)malloc(sizeof(struct Tree));
	root->data=data;
	root->left=NULL;
	root->right=NULL;
	return root;
}
void putdata(int path[],int pathlen,int sum)
{
	int i=0;
	int temp=0;
	for(i=0;i<pathlen;i++)
	{
		temp+=path[i];
	//	printf("%d->",path[i]);
	}
	if(temp==sum)printf("Exists");
}
void print_path(struct Tree* root,int path[],int pathlen,int sum)
{
 if(root==NULL)return ;
 //printf("root->data %d \n",root->data);
 path[pathlen]=root->data;
 pathlen++;
 if(root->left==NULL && root->right==NULL)
 {
 	putdata(path,pathlen,sum);
 	//printf("\n");	
 }
 else
 {
  print_path(root->left,path,pathlen,sum);
 print_path(root->right,path,pathlen,sum);	
 }
}
int main()
{
	struct Tree* root=newnode(10);
	root->left=newnode(11);
	root->right=newnode(12);
	root->left->left=newnode(1);
	root->left->right=newnode(2);
	root->right->left=newnode(4);
	root->right->right=newnode(15);
	int path[100];
	print_path(root,path,0,26);
	return 0;
}
