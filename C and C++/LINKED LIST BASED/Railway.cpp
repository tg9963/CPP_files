#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct ticket
{
	int pnr;
	char pref;
	char status;
	struct ticket* next;	
};
struct ticket* M_head=(struct ticket*)malloc(sizeof(struct ticket));
struct ticket* M_curr=M_head;
struct ticket* R_head=(struct ticket*)malloc(sizeof(struct ticket));
//R_head->pnr=0;
struct ticket* R_curr=R_head;
struct ticket* W_head=(struct ticket*)malloc(sizeof(struct ticket));
//W_head->pnr=0;;
struct ticket* W_curr=W_head;
int available=2;
int rac=2;
int waiting=5;
int inc=12345;
void initialize(struct ticket** M_head,struct ticket** R_head,struct ticket** W_head)
{
	struct ticket* temp=*M_head;
	temp->pnr=0;
	//temp->status="UNRESERVED";
	temp->next=NULL;
	temp=*R_head;
	temp->pnr=0;
//	temp->status="UNRESERVED";
	temp->next=NULL;
	temp=*W_head;
	temp->pnr=0;
//	temp->status="UNRESERVED";
	temp->next=NULL;
}
int reserve()
{
	char pref='L';
	if(available>0)
	{
		struct ticket* node=(struct ticket*)malloc(sizeof(struct ticket));
		cout<<"Enter ur bearth pref (L|U) [Default Lower ] "<<endl;
		cin>>pref;
		if(pref=='U')
		{
			node->pref='U';		
		}
		else
		{
			node->pref='L';
		}
			inc+=1;
			node->pnr=inc;
			//cout<<"hey1";
			node->status='R';
			node->next=NULL;
		M_curr->next=node;
		M_curr=node;
		available--;
		cout<<"\nReservation Successfull \n";
		cout<<"*********************************\n";
		cout<<" PNR NUMBER: "<<M_curr->pnr<<endl;
		cout<<" PREFERENCE: "<<M_curr->pref<<endl;
		cout<<" STATUS: "<<M_curr->status<<endl;
		return 1;
	}
	else if(rac>0)
	{
		rac--;
		struct ticket* node=(struct ticket*)malloc(sizeof(struct ticket));
		cout<<"\nEnter ur bearth pref (L|U) [Default Lower ] "<<endl;
		cin>>pref;
		if(pref=='U')
		{
			node->pref='U';		
		}
		else
		{
			node->pref='L';
		}
			inc+=1;
			node->pnr=inc;
			node->next=NULL;
			node->status='r';
		R_curr->next=node;
		R_curr=node;
		cout<<"\nRAC  \n";
		cout<<"*********************************\n";
		cout<<" PNR NUMBER: "<<R_curr->pnr<<endl;
		cout<<" PREFERENCE: "<<R_curr->pref<<endl;
		cout<<" STATUS: "<<R_curr->status<<endl;
		return 1;
	}
	else if(waiting>0)
	{
		waiting--;
		struct ticket* node=(struct ticket*)malloc(sizeof(struct ticket));
		cout<<"\nEnter ur bearth pref (L|U) [Default Lower ] "<<endl;
		cin>>pref;
		if(pref=='U')
		{
			node->pref='U';		
		}
		else
		{
			node->pref='L';
		}
			inc+=1;
			node->pnr=inc;
			node->status='W';
			node->next=NULL;
		W_curr->next=node;
		W_curr=node;
		cout<<"\nWAITING \n";
		cout<<"*********************************\n";
		cout<<" PNR NUMBER: "<<W_curr->pnr<<endl;
		cout<<" PREFERENCE: "<<W_curr->pref<<endl;
		cout<<" STATUS: "<<W_curr->status<<endl;
		return 1;
	}
	else return 0;
}
/*
void print_ticket()
{
	if(M_curr!=NULL)
	{
		cout<<" PNR NUMBER: "<<M_curr->pnr<<endl;
		cout<<" PREFERENCE: "<<M_curr->pref<<endl;
		cout<<" STATUS: "<<M_curr->status<<endl;
	}
}
*/
void availablity()
{
	cout<<"Availability : "<<available<<endl;
	cout<<"RAC : "<<rac<<endl;
	cout<<"Waiting : "<<waiting<<endl;
}
void update2()
{
	waiting++;
	struct ticket* temp=R_head->next;
	struct ticket* prev=NULL;
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->pnr=W_head->next->pnr;
	temp=W_head->next;
	W_head->next=W_head->next->next;
	free(temp);
}
void update(struct ticket** tick)
{
	if(rac<4)
	{
		rac++;
		struct ticket* temp=R_head->next;
		//tick->pref=temp->pref;
		//tick->status=temp->status;
		(*tick)->pnr=temp->pnr;
		R_head->next=R_head->next->next;
		free(temp);
		
		if(waiting<5)
		{ 
			update2();
			rac--;
		}
		return ;
		
	}
	else if(waiting<5)
	{
		waiting++;
		struct ticket* temp=W_head;
		//tick->pref=temp->pref;
		//tick->status=temp->status;
		(*tick)->pnr=W_head->pnr;
		W_head=W_head->next;
		free(temp);
		return ;
	}
}
void update_rac(struct ticket** tick)
{
	 if(waiting<5)
	{
		waiting++;
		struct ticket* temp=W_head->next;
		//tick->pref=temp->pref;
		//tick->status=temp->status;
		(*tick)->pnr=temp->pnr;
		W_head->next=W_head->next->next;
		free(temp);
		return ;
	}
}
int del(int pnr)
{
	struct ticket* temp=M_head->next;
	struct ticket* prev=NULL;
	struct ticket* del_node;
	while(temp)
	{
		if(temp->pnr==pnr)
		{
			if(rac<4 || waiting<5)
			{
				update(&temp);
				return 1;
			}
			else
			{
				if(temp->next==NULL)
			{
				if(prev==NULL)
				{
					del_node=temp;
					W_head->next=NULL;
				}
				else
				{
					del_node=temp;
					prev->next=NULL;
				}	
			}
			else
			{
				if(prev==NULL)
				{
					del_node=temp;
					temp=temp->next;
				}
				else
				{
					del_node=temp;
					prev->next=temp->next;
				}
			}
			free(del_node);
			available++;
			return 1;
			}
		}
		prev=temp;
		temp=temp->next;
	}
	temp=R_head->next;
	prev=NULL;
	while(temp)
	{
		if(temp->pnr==pnr)
		{	
			if(waiting<5)
			{
				update_rac(&temp);
				return 1;
			}
			else
			{
				if(temp->next==NULL)
		    {
				if(prev==NULL)
				{
					del_node=temp;
					R_head->next=NULL;
				}
				else
				{
					del_node=temp;
					prev->next=NULL;
				}	
			}
			else
			{
				if(prev==NULL)
				{
					del_node=temp;
					temp=temp->next;
				}
				else
				{
					del_node=temp;
					prev->next=temp->next;
				}
			}
			free(del_node);
			rac++;
			return 1;
			}
		}
		prev=temp;
		temp=temp->next;
	}
	temp=W_head->next;
	prev=NULL;
	while(temp)
	{
		if(temp->pnr==pnr)
		{
			if(temp->next==NULL)
			{
				if(prev==NULL)
				{
					del_node=temp;
					W_head->next=NULL;
				}
				else
				{
					del_node=temp;
					prev->next=NULL;
				}	
			}
			else
			{
				if(prev==NULL)
				{
					del_node=temp;
					temp=temp->next;
				}
				else
				{
					del_node=temp;
					prev->next=temp->next;
				}
			}
			free(del_node);
			waiting--;
			return 1;
		}
		prev=temp;
		temp=temp->next;
	}
return 0;	
}

void cancel()
{
	int temp_pnr;
	cout<<"Enter Your PNR : ";
	cin>>temp_pnr;
	int mode=del(temp_pnr);
	if(mode==0)
	{
		cout<<"INVALID PNR! \n";
		return ;
	}
	else
	{
		cout<<"Cancelled Successfully \n";
		return ;
	}
}
void print()
{
	struct ticket* temp=M_head->next;
	while(temp!=NULL)
	{
		cout<<"\n*********************************\n";
		cout<<" PNR NUMBER: "<<temp->pnr<<endl;
		cout<<" PREFERENCE: "<<temp->pref<<endl;
		cout<<" STATUS: "<<temp->status<<endl;
		temp=temp->next;
	}
	temp=R_head->next;
	while(temp!=NULL)
	{
		cout<<"\n*********************************\n";
		cout<<" PNR NUMBER: "<<temp->pnr<<endl;
		cout<<" PREFERENCE: "<<temp->pref<<endl;
		cout<<" STATUS:"<<temp->status<<endl;
		temp=temp->next;
	}
	temp=W_head->next;
	while(temp!=NULL)
	{
		cout<<"\n*********************************\n";
		cout<<" PNR NUMBER: "<<temp->pnr<<endl;
		cout<<" PREFERENCE: "<<temp->pref<<endl;
		cout<<" STATUS: "<<temp->status<<endl;
		temp=temp->next;
	}
}
int main()
{
	initialize(&M_head,&R_head,&W_head);
	while(1)
	{
	cout<<"\n\n****************************************** \n\n";
	cout<<"\n1.Reserve 2.Available 3.Cancel 4.Print \n";
	int choice;
	cin>>choice;
	switch(choice)
	{
		case 1:
			if(reserve())
			{
				//cout<<"Reservation Successfull \n";
				//cout<<"*********************************\n";
				//print_ticket();
			}
			else
			{
				cout<<"Reservation Unsuccessfull \n";
				cout<<"*********************************\n";
			}
			break;
		case 2:
			availablity();
			break;
		case 3:
			cancel();
			break;
		case 4:
			print();
			break;
		default:
			cout<<"Invalid Choice ! \n";
			cout<<"*********************************\n";
			break;
	}
	char ch;
	cout<<"\n\n Continue ? y/n \n";
	cin>>ch;
	if(ch!='y')
	{
		cout<<"\n\n Thanks For using :-) \n";
		break;
	}	
	}	
return 0;
}
