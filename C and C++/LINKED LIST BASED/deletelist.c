#include<stdio.h>
#include<stdlib.h>
struct list 
{
	int data;
	struct list *next;
};
struct list *head=NULL;
struct list *curr=NULL;
void create_list(int val)
{
	struct list *p=(struct list*)malloc(sizeof(struct list));
	p->data=val;
	p->next=NULL;
	head=curr=p;
}
void add_list(int val)
{
	struct list *p=(struct list *)malloc(sizeof(struct list));
	p->data=val;
	p->next=NULL;
	curr->next=p;
	curr=p;
}
void delete_list(int ind)
{
	int b=0;
	struct list *p=NULL;
	struct list *q=NULL;
	p=head;
	if(ind <0 )return ;
	if(ind==1)
	{
		p=head;
		head=head->next;
		free(p);
		return ;
	}
	while((p!=NULL) && b<ind-1 )
	{
			q=p;
			p=p->next;
			b++;
	}
	if(p==NULL)return ;
	else
	{
		q->next=p->next;
		free(p);
		return ;
	}
}
void print_list()
{
	struct list *p=head;
	while(p!=NULL)
	{
		printf("[%d]",p->data);
		p=p->next;
	}
}
int main()
{
	int a,index,choice;
	while(1)
	{
		printf("\n 1.create list 2.add 3.delete at index 4.print \n");
		scanf("%d",&index);
		switch(index)
		{
			case 1:
				printf("\n Enter the head element \n");
				scanf("%d",&a);
				create_list(a);
				break;
			case 2:
				printf("\n Enter the element \n");
				scanf("%d",&a);
				add_list(a);
				break;
			case 3:
				printf("\n enter the index \n");
				scanf("%d",&index);
				delete_list(index);
				break; 
			case 4:
				printf("\n list ");
				print_list();
				break;
			default :
				printf("\n invalid !");
				break;
		}
	}
	return 0;
}
