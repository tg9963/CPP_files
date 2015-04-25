#include<iostream>
#include<stdlib.h>
#define MAX_SIZE 10
using namespace std;

struct heap
{
	int* array;
	int capacity;
	int count;
};

struct heap* create_heap(int n)
{
	struct heap* h=(struct heap*)malloc(sizeof(int));
	h->array=(int*)malloc(n*sizeof(int));
	h->capacity=n;
	h->count=0;
	return h;
}

int left_child(struct heap* h,int i)
{
	int left=2*i+1; 
	if(left>=h->count)return -1;
	return left;
}

int right_child(struct heap* h,int i)
{
	int right=2*i+2; 
	if(right>=h->count)return -1;
	return right;
}

void max_heapify(struct heap* h,int i)
{
	if(h==NULL)return ; 
	int max,temp=0;
	int left=left_child(h,i);
	int right=right_child(h,i);
	if(left!=-1 && h->array[left]>h->array[i])
		max=left;
	else max=i;
	if(right!=-1 && h->array[right]>h->array[max])
		max=right;
	if(max!=i)
	{
		temp=h->array[max];
		h->array[max]=h->array[i];
		h->array[i]=temp;
	//	if(max>=(h->count-1))return ;
		max_heapify(h,max);
	}
}

struct heap* BUILD(int n)
{
	struct heap* h=create_heap(n);
 	cout<<"\nEnter Elements: ";
	for(int i=0;i<n;i++)
		cin>>h->array[i];
	
	h->count=n;
	
	for(int i=(n-1)/2;i>=0;i--)
		max_heapify(h,i);
	return h;
}

struct heap* rebuild_heap(struct heap* h,int n)
{
	if(n>h->capacity)
	{
		int *old=h->array;
		h->array=(int*)malloc(n*sizeof(int));
		for(int i=0;i<h->count-1;i++)
		{
			h->array[i]=old[i];
		} 
		free(old);
	}
	return h;
}

int get_parent(struct heap* h,int num)
{
	if(num>(h->count-1))return -1;
	int parent=(num-1)/2;
	if(num<0)return -1;
	return parent;
}
struct heap* insert(struct heap* h,int data)
{
	if(h==NULL)
	{
		h=create_heap(MAX_SIZE); 
		h->array[0]=data;
		h->count++;
		return h;
	}
	else
	{
		h->count+=1;
		if(h->count>h->capacity)
			{
				h=rebuild_heap(h,2*h->capacity);
			}
		h->array[h->count-1]=data;
		int parent=get_parent(h,h->count-1);
		if(parent !=-1)for(int i=parent;i>=0;i--)max_heapify(h,i);
		return h;
	}
	
}

void print_heap(struct heap* h)
{
	if(h)
	{
		for(int i=0;i<h->count;i++)cout<<h->array[i]<<"  ";
	}
}

struct heap* heap_sort(struct heap* h)
{
	int temp;
	int n=h->count;
	
	for(int i=n-1;i>0;i--)
	{
		temp=h->array[0];
		h->array[0]=h->array[h->count-1];
		h->array[h->count-1]=temp;
		h->count--;
		max_heapify(h,0);
	}
	h->count=n;
	return h;
}

void delete_heap(struct heap* h)
{
	if(h==NULL)return;
	h->capacity=0;
	h->count=0;
	free(h->array);
}
int get_max(struct heap* h)
{
	if(h==NULL)return 0;
	int max=h->array[0];
	h->array[0]=h->array[h->count-1];
	h->count--;
	max_heapify(h,0);
	return max;
}

int main()
{
	int n,temp;
	cout<<"Enter n: ";
	cin>>n;
	struct heap* h=NULL;
	h=BUILD(n);
	cout<<endl<<endl;
	print_heap(h);
	cout<<"Insert elemnt : ";
	cin>>temp;
	h=insert(h,temp);
	cout<<endl<<endl;
	print_heap(h);
	cout<<endl<<endl;
	h=heap_sort(h);
	cout<<endl<<endl;
	print_heap(h);
}
