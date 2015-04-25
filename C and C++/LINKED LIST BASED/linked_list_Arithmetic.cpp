#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
struct number
{
	int data;
	struct number* next;
};
struct number* form(string num)
{
	if(num.size()<=0)return NULL;
	struct number* head=(struct number*)malloc(sizeof(struct number));
	head->data=num[0]-48;
	num=num.substr(1,num.size());
	head->next=form(num);
	return head;
}
void print_num(struct number* head)
{
	struct number* temp=head;
	while(temp)
	{
		cout<<temp->data;
		temp=temp->next;
	}
}
struct number* reverse(struct number* head1)
{
	struct number* curr1=head1;
	struct number* prev=NULL;
	struct number* next;
	int n=0; 
	while(curr1)
	{
 		next=curr1->next;
 		curr1->next=prev;
 		prev=curr1;
 		curr1=next;
	}
	head1=prev;
	prev=NULL;
	next=NULL;
	return head1;
}
struct number* addition(struct number* head1,number* head2,int *flow)
{
	if(head1==NULL && head2==NULL)return NULL;
	if(head1==NULL)return head2;
	if(head2==NULL)return head1;
    struct number* head=(struct number*)malloc(sizeof(struct number));
    head->data=head1->data+head2->data+(*flow);
    if(head->data>=10)
	{
		*flow=1;
		head->data=head->data%10;
	}
	else
	{
		*flow=0;
	}
    head->next=addition(head1->next,head2->next,flow);
	return head;
}
int main()
{
 	cout<<"enter number 1 \n";
	string num1;
	cin>>num1;
	cout<<"enter number 2 \n";
	string num2;
	cin>>num2;
	struct number* number1=form(num1);
	struct number* number2=form(num2);
	number1=reverse(number1);
	number2=reverse(number2);
	int flow=0;
	struct number* number3=addition(number1,number2,&flow);
	number3=reverse(number3);
	if(flow==1)number3->data+=10;
	cout<<endl;
	print_num(number3);
	return 0;
}
