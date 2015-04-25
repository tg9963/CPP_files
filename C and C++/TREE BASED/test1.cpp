#include<iostream>
#include<stdlib.h>
using namespace std;

struct list
{
	int data; 
	struct list* next;
	struct list* prev;
};
struct queue
{
	struct list* front;
	struct list* rear;
};


struct queue* create_queue()
{
	struct queue* q=(struct queue*)malloc(sizeof(struct queue));
	q->front=NULL;
	q->rear=NULL;
}

int isempty(struct queue* q)
{
	return (q->front==NULL);
}
 
int pop_back(struct queue* q)
{
if(q->rear!=NULL)
{
	 	int temp;
		struct list* element=q->rear;
		if(q->rear->prev)q->rear=q->rear->prev;
		else q->rear=NULL;
		temp=element->data;
	 //	free(element);
		return temp; 
}
return -1;
}

struct list* newnode(int i)
{
	struct list* element=(struct list*)malloc(sizeof(struct list));
	element->data=i;
	element->next=NULL;
	element->prev=NULL;
	return element;
}
void push_back(struct queue* q,int i)
{
		struct list* element=newnode(i);
		if(q->rear)
		{
			q->rear->next=element;
			element->prev=q->rear;	
		}
		q->rear=element;
		if(q->front==NULL)
		{
			q->front=q->rear;
		}
}

int pop_front(struct queue* q)
{	 
if(q->front!=NULL)
{
		int data;
		struct list* temp=q->front;
		if(q->front->next)q->front=q->front->next; 
		else q->front=NULL;
		data=temp->data;
	 	//free(temp);  
	 	return data; 
}
return -1;
}
/*
void push_front(struct queue* q)
{
	if(!isfull(q))
	{
		q->array[++q->rear]=i;
	}
}
*/

int front(struct queue* q)
{
	if(q->front!=NULL)
	{
		struct list* temp=q->front;
		return temp->data;
	}
	return -1;
}

int back(struct queue* q)
{
	if(q->rear!=NULL)
	{
		struct list* temp=q->rear;
		return temp->data;
	}	
	return -1;
}

int get_max_in_window(int a[],int b[],int n,int w)
{
	if(w>n)
	{
		cout<<"Not possible ";
		return 0;
	}
	struct queue* q=create_queue();
	
	for(int i=0;i<w;i++)
	{
		while(!isempty(q) && (back(q)!=-1) && a[i]>=a[back(q)])
		{	
	 		  pop_back(q);
		}
		push_back(q,i);
	}  
	
	for(int i=w;i<n;i++)
	{
	 	b[i-w]=a[front(q)];
		while(!isempty(q) && (back(q)!=-1) &&a[i]>=a[back(q)])
		{
					pop_back(q);
		}	
	 	while(!isempty(q) && (front(q)!=-1) && front(q)<=(i-w))
		{
	 		pop_front(q);
	 	}
		push_back(q,i);
	}
	if((front(q)!=-1))b[n-w]=a[front(q)];
	return 1;
}

int main()
{
	int n;
	cout<<"\nEnter n: ";
	cin>>n;
	int a[n];
	cout<<"\nEnter array: ";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int w;
	cout<<"\nEnter window: ";
	cin>>w;
	int b[n-w];
	if(get_max_in_window(a,b,n,w))
	{
		cout<<"\nMax array: ";
		for(int i=0;i<(n-w);i++)
		{
			cout<<b[i]<<"   ";
		}
	}
	return 0;
}
