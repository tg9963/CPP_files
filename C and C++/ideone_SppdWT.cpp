#include<iostream>
using namespace std;
struct node
{
	node* lchild;
	int data;
	node* rchild;
	node()
	{
		lchild=NULL;
		rchild=NULL;
	}
}*root=NULL;
node* fun(node* root,int arr[],int low,int high)
{
	if(!root)
	    root=new node();
	if(low==high)
	{
		root->data=arr[low];
		return root;
	}
	int mid=(low+high)/2;
	root->lchild=fun(root->lchild,arr,low,mid);
	root->rchild=fun(root->rchild,arr,mid+1,high);
	root->data=root->lchild->data+root->rchild->data;
	return root;
}
void update(node* root,int *arr,int ind,int low,int high,int val)
{
	if(low==high)
	{
		root->data=val;
		return;
	}
	int mid=(low+high)/2;
	if(ind>mid)
	    update(root->rchild,arr,ind,mid+1,high,val);
    else if(ind<=mid)
         update(root->lchild,arr,ind,low,mid,val);
	root->data=root->lchild->data+root->rchild->data; 
         
}
void display(node* root)
{
   if(root!=NULL)
   {
   	display(root->lchild);
   	cout<<root->data<<" ";
   	display(root->rchild);
   }
}
int main()
{
	int arr[]={3,5,1,7,9,6};
	int i,r,ind,val;
	int n=sizeof(arr)/sizeof(arr[0]);
	cout<<"the inorder trversal of segment tree is.\n";
	root=fun(root,arr,0,n-1);
	node* ptr=root;
	display(root);
    cout<<"\n"<<"enter the range i and r values.\n";
    cin>>i>>r;
    root=NULL;
    cout<<fun(root,arr+i,0,r-i)->data<<" is the range sum.\n";
    cout<<"enter the index of the array and modified value.\n";
    cin>>ind>>val;
    update(ptr,arr,ind,0,n-1,val);
    display(ptr);
	return 0;
}