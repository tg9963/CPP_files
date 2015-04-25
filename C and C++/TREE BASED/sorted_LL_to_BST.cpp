#include<iostream>
#include<stdlib.h>
#include<algorithm>
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

void print_list(struct tree* root)
{
	while(root)
	{
		cout<<root->data<<"  ";
		root=root->right;
	}
} 
void print_inorder(struct tree* root)
{
	if(root)
	{
		print_inorder(root->left);
		cout<<root->data<<"  ";
		print_inorder(root->right);
	}
}
struct tree* construct_list(int *a,struct tree* head,int size)
{
	if(size<=0)return NULL;
	static struct tree* prev;
	static int index;
	if(index<size)
	{
		head=newnode(a[index]);
		index++;
		if(prev==NULL)prev=head;
		else 
		{
			head->left=prev;
			prev->right=head;
			prev=head;
		}
		head->right=construct_list(a,head->right,size);
		return head;
	}
	else
	return NULL;
}
struct tree* find_middle(struct tree* head1,struct tree** right)
{
	struct tree* n1=head1;
	struct tree* n2=head1;
	while(n2 && n2->right )
	{
		n2=n2->right;
		n2=n2->right;
		n1=n1->right;
	}
	*right=n1->right;
	cout<<(*right)->data<<"  ";
	n1->right=NULL;
	return n1;
}
int find_nodes(struct tree* node)
{
	int count=0;
	struct tree* temp=node;
	while(temp)
	{
		temp=temp->right;
		count++;
	}
	return count;
}
struct tree* find(struct tree* node,int index)
{
	int count=0;
	struct tree* temp=node;
	while(temp)
	{
		if(count==index)return temp;
		temp=temp->right;
		count++;
	}
	return NULL;
}

struct tree* convert(struct tree* head)
{
	if(head==NULL )return NULL;
	struct tree* right=NULL;
	struct tree* middle=find_middle(head,&right);
	if(middle)cout<<"\nc: "<<middle->data<<"  \n";
	middle->left=convert(head);
	middle->right=convert(right);
	return middle;
}
struct tree* convert1(struct tree* head,int start,int end)
{
	if(head==NULL || start==end )return NULL;
	int mid=start+(end-start)/2;
	struct tree* middle=find(head,mid);
	struct tree* root=middle;
	if(root)cout<<"\nc: "<<root->data<<"  \n";
	root->left=convert1(middle->left,0,mid);
	root->right=convert1(middle->right,mid+1,end);
	return root;
}
int main()	
{
	cout<<"enter n: ";
	int n,temp;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
	 	cin>>a[i];
	}
	struct tree* head;
	head=construct_list(a,head,n);
	print_list(head);
	//int num=find_nodes(head);
	struct tree* root=convert(head);
	print_inorder(root);	
 	return 0;
}
