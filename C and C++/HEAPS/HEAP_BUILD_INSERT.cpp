#include<iostream>
#include<stdlib.h>
using namespace std;

struct heap
{
	int * array;
	int capacity;
	int count;
};
struct heap* create_empty_heap(int n)
{
	struct heap* h=(struct heap*)malloc(sizeof(struct heap));
	h->array=(int*)malloc(n*sizeof(int));
	h->capacity=n;
	h->count=0;
	return h;
}
int left_child(struct heap* h,int parent)
{
	if(h==NULL || h->count==0 )return -1;
	int left=2*parent+1;
	if(left>=h->count)return -1;
	return left;
}

int right_child(struct heap* h,int parent)
{
	if(h==NULL || h->count==0 )return -1;
	int right=2*parent+2;
	if(right>=h->count)return -1;
	return right;
}
/*
void max_heapify(struct heap* h,int i)
{
	
	int left=left_child(h,i);
	int right=right_child(h,i);
	int max;
	cout<<"\ni: "<<i<<" l: "<<left<<" r: "<<right<<endl;
	if(left!=-1 && h->array[left]>h->array[i])
		max=left;
	else max=i;
	if(right !=-1 && h->array[right]>h->array[max] )
		max=right;
	if(max!=i)
	{
		int temp=h->array[i];
		h->array[i]=h->array[max];
		h->array[max]=temp;
		if((max> h->count-1 ) || max<=0)return ;
		max_heapify(h,max);
	}
}
 */
void min_heapify(struct heap* h,int i)
{
	int left=left_child(h,i);
	int right=right_child(h,i);
	int min;
 	if(  left!=-1 && h->array[left]<h->array[i])
		min=left;
	else min=i;
	if(right !=-1 && h->array[right]<h->array[min] )
		min=right;
	if(min!=i)
	{
 		int temp=h->array[i];
		h->array[i]=h->array[min];
		h->array[min]=temp;
		if((min > h->count-1 ) || min< 0)return ;
		min_heapify(h,min);
	}
	
}
void print_heap(struct heap* h)
{
	if(h==NULL)return;
	cout<<endl<<endl;
	for(int i=0;i<h->count;i++)cout<<h->array[i]<<"   ";
}
int get_top(struct heap* h)
{
	if(h->count==0)return -1;
	int min=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	min_heapify(h,0);
	return min;
}
struct heap* BUILD(int n)
{
	struct heap* h=create_empty_heap(n);
	int arr[n];
	cout<<"enter elemnts : ";
	for(int i=0;i<n;i++)
	{
		cin>>h->array[i];
	}
	h->count=n;
	for(int i=(n-1)/2;i>=0;i--)
	{
		min_heapify(h,i);
	}
	
	return h;
}

int main()
{
	cout<<"Enter n: ";
	int n;
	cin>>n;
	struct heap* h=BUILD(n); 
	print_heap(h);
	cout<<"\n\nEnter k: ";
	int k,temp=0;
	cin>>k;
	for(int i=0;i<k;i++)
	{
			temp=get_top(h);
	}
	cout<<"\n\n "<<k<<" min element: "<<temp;
	return 0;
}
