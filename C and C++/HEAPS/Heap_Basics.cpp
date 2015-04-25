#include<iostream>
#include<stdlib.h>
using namespace std;

struct heap
{
	int *array;
	int capacity;
	int count;
	int heap_type;
};


int parent(struct heap* h,int i)
{
	if(h==NULL)return -1;
	if(i<=0 || i>=h->count)return -1;
	return (i-1)/2;
}

int left_child(struct heap* h,int i)
{
	if(h==NULL)return -1;
	int left=2*i+1;
	if(left>=h->count)return -1;
	return left;
}

int right_child(struct heap* h,int i)
{
	if(h==NULL)return -1;
	int right=2*i+2;
	if(right>=h->count)return -1;
	return right;
}

int get_min(struct heap* h)
{
	if(h==NULL)return -1;
	if(h->count==0)return -1;
	return h->array[0];
}

void heapify(struct heap* h,int i)
{
	int max,temp;
	int left=left_child(h,i);
	int right=right_child(h,i);
	if(left!=-1 && h->array[left]>h->array[i])
		max= left;
	else
		max=i;
	if(right!=-1 && h->array[right]>h->array[max])
		max=right;
	if(max!=i)
	{
		temp=h->array[i];
		h->array[i]=h->array[max];
		h->array[max]=temp;
		if(max>(h->count - 1) || max<0 )
		return ;
		heapify(h,max);
	}	
}
struct heap* create_heap(int capacity,int heap_type)
{
	struct heap* h=(struct heap*)malloc(sizeof(struct heap));
	h->count=0;
	h->capacity=capacity;
	h->heap_type=heap_type;
	h->array=(int *)malloc(h->capacity * sizeof(int));
	return h;
}

void insert(struct heap* h,int data)
{
	int i;
	//if(h->count==h->capacity)resize_heap(h);
	h->count++;
	
}

struct heap* construct_heap(struct heap* h,int n)
{
	int arr[n];
	h=create_heap(n,1);
	cout<<"\nenter elements: ";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		h->array[i]=arr[i];
	} 
	/*
	for(int i=0;i<n;i++)
	insert(h,arr[i]);
	*/
	h->count=n;
	for(int i=(n-1)/2;i>=0;i--)heapify(h,i);
	return h;
}
void print_heap(struct heap* h)
{
	for(int i=0;i<h->capacity;i++)
	{
		cout<<h->array[i]<<"     ";
	}
}
int main()
{
	int n;
	cout<<"Enter size: ";
	cin>>n;
	struct heap* h=NULL;
	h=construct_heap(h,n);
	print_heap(h);
	return 0; 
}
