#include<iostream>
#include<stdlib.h>
#include<map>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

map<int,int> m; 
struct Node *newNode(int item)
{
    struct Node *temp =  (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

 
void rightViewUtil(struct Node *root, int level, int *max_level)
{
     
    if (root==NULL)  return;

     
    if (*max_level < level)
    {
    	m[root->data]=1;
        *max_level = level;
    }
    rightViewUtil(root->right, level+1, max_level);
    rightViewUtil(root->left, level+1, max_level);
}

void rightView(struct Node *root)
{
    int max_level = 0;
    rightViewUtil(root, 1, &max_level);
}

struct Node* construct_tree(int arr[],long n,long pos)
{
	if(pos>=n)
	{
		return NULL;
	}
	else
	{ 
		struct Node* node=newNode(arr[pos]);
		node->left=construct_tree(arr,n,2*pos+1);
		node->right=construct_tree(arr,n,2*pos+2);
		return node;
	}
	
}
void leftViewUtil(struct Node *root, int level, int *max_level)
{
     
    if (root==NULL)  return;
   
    if (*max_level < level)
    {
        	m[root->data]=2;
        *max_level = level;
    }
 
     
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
}
 
 
void leftView(struct Node *root)
{
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
}

void print_tree(struct Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"  ";
		print_tree(root->left);
		print_tree(root->right);
	}
}

int main()
{
int test;
cin>>test;
while(test--)
{
	long n;
	cin>>n;
	int arr[n];
	for(long i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	struct Node* root=construct_tree(arr,n,0);
	print_tree(root);
	cout<<endl;
	m.clear();
		leftView(root);
	rightView(root);
	map<int,int>::iterator it;
	cout<<endl;
	for(it=m.begin();it!=m.end();it++)
	{
		if((*it).second == 1)
		{
			if((*it).first!=0)
			cout<<(*it).first<<endl;
		}
	}
	
	for(it=m.begin();it!=m.end();it++)
	{
		if((*it).second == 2)
		{
			if((*it).first!=0)
			cout<<(*it).first<<endl;
		}
	}
}

    return 0;
}

