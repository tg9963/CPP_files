#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<list>
using namespace std;

struct node
{
	string name;
	char mode; // r/w/a
	int type;  // -1 root directory , 1 - directory , 0 - file
	int size;
	list<struct node*> *l;
};

struct node* create_node(string name,char mode,int type,int size)
{
	struct node* element=(struct node*)malloc(sizeof(struct node));
	element->name=name;
	element->mode=mode;
	element->type=type;
	element->size=size;
	element->l=new list<struct node*>[1];
	cout<<"  ";
	element->l[0].push_back(NULL);
	return element;
}

void print_all(struct node* curr)
{
	if(curr==NULL)return ;
	if(curr->type==-1)
	{
		cout<<"\n****Root********\n";
	}
	else if(curr->type==1)
	{
		cout<<"--";
	}
	else
	{
		cout<<"-------";
	}
	cout<<"Name:  "<<curr->name<<"  Mode: "<<curr->mode;
	cout<<endl;
	list<node*>::iterator it;
	int i=0;
	for(it=curr->l[0].begin();it!=curr->l[0].end();it++)
	{
		print_all(*it);
	}
}

void diaplay_directories(struct node* curr)
{
 
	if(curr==NULL)return ;
    if(curr->type==1)
	{
		cout<<curr->name<<endl;
	}
	list<struct node*>::iterator it;
	for(it=curr->l[0].begin();it!=curr->l[0].end();it++)
	{
		print_all(*it);
	}
}


void add_directory(struct node* parent)
{
	if(parent==NULL)
	{
		return ;
	}
	cout<<"Enter the name of Directory \n";
	string name;
	cin>>name;
	cout<<"Enter the mode of Directory (r/w/a)\n";
	char mode;
	cin>>mode;
	int type=1;
	int size=0;
	struct node* new_element=create_node(name,mode,type,size);
	new_element->l[0].push_back(NULL);
	(parent->l[0]).push_back(new_element);
}
void add_file(struct node* parent,string parent_name)
{
	if(parent==NULL)
	{
		return ;
	}
	list<struct node*>::iterator it;
	for(it=parent->l[0].begin();it!=parent->l[0].end();it++)
	{
		if(((*it)->name).find(parent_name)<((*it)->name).size())
		{
			cout<<"Hey 2";
		  	cout<<"Enter the name of file \n";
			string name;
			cin>>name;
			cout<<"Enter the mode of file (r/w/a)\n";
			char mode;
			cin>>mode;
			int type=0;
			int size=1;
			struct node* new_element=create_node(name,mode,type,size);
			new_element->l[0].push_back(NULL);
			((*it)->l[0]).push_back(new_element);	
		}
	}
	
}

int main()
{
	cout<<"Create Root Directory (Y/N)\n";
	char ch;
	cin>>ch;
	struct node* first=NULL;
	if(ch=='Y')
	{
		cout<<"Enter the name of root Directory \n";
		string name;
		cin>>name;
		//cout<<"Enter the mode of root Directory (r/w/a)\n";
		char mode='a';
		//1cin>>mode;
		int type=-1;
		int size=0;
		first=create_node(name,mode,type,size);
		cout<<endl<<endl<<endl;
		int count=0;
		while(1)
		{
		cout<<"1. Display All\n"<<
		"2. Add Directory \n"<<
		"3. Add file \n"<<
		"4. Delete Directory \n"<<
		"5. Delete File \n"<<
		"6. Delete Root Directory \n";
		int choice;
		string parent_name;
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nDisplaying all files....";
				print_all(first);
				cout<<"**************************************";
				cout<<endl;
				break;
			case 2:
				add_directory(first);
				cout<<endl<<endl;
				cout<<" Directory Added successfully ...\n";
				//print_all(first);
				break;
			case 3:
				cout<<"\nDisplaying all Directories.... choose the parent directory to add file \n";
				diaplay_directories(first);
				cout<<endl;
				cout<<" Enter the parent directory \n\n\n";
				cin>>parent_name;
				add_file(first,parent_name);
				cout<<endl<<endl;
				cout<<"After adding the file...\n";
				print_all(first);
				break;
			case 4:
				break;
			default:
				break;
		 }
		 
		 if(count++ == 5)
		 {
		 	break;
		 }
		}
	}
	return 0;
}
