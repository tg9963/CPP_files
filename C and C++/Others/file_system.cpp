#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

struct properties
{
	string mode;
	string view;
	string type_of_file;
	int size;
	string name;
};


struct tree
{
	struct properties* p;
	int num_of_child;
	vector<struct tree*> v;	
};

struct properties* initialize_prop(string mode,string view,string type_of_file,int size,string name)
{
	struct properties* node=(struct properties*)malloc(sizeof(struct properties));
	node->mode=mode;
	node->view=view;
	node->type_of_file=type_of_file;
	node->size=size;
	node->name=name; 
	return node;
}

struct tree* create_tree_node(string mode,string view,string type_of_file,int size,string name)
{
	struct tree* tree_node=(struct tree*)malloc(sizeof(struct tree));
	tree_node->num_of_child=0;
	tree_node->p=initialize_prop( mode, view,  type_of_file,  size,  name);
	return tree_node;
}



int main()
{
	cout<<"1) Create Root \n2) Create Directory \n3) Create File \n4) Delete File \n5) Delete Directory \n6) Get Properties	";
	int ch;
	struct tree* root=NULL;
	string mode;
	string view;
	string type_of_file;
	int size;
	string name;
	
	int lev=0;
	/*
		Lev-0 -> Root Lev-1 ->Parent Lev-2 Files
	*/
	
	switch(ch)
	{
		case 1:
			cout<<"\nEnter Root Directory Details: "
			cout<<"\nEnter the Name: ";
			cin>>name;
			cout<<"\nEnter the mode (r/w/a): ";
			cin>>mode;
			cout<<"\nEnter the View (Hidden (y/n) ): ";
			cin>>view;
			type_of_file="ROOT_DIRECTORY";
			size=0;
			root=create_tree_node(mode,view,type_of_file,size,name);
			break;
		case 2:
			cout<<"\nEnter Parent Directory Details: "
			cout<<"\nEnter the Name: ";
			cin>>name;
			cout<<"\nEnter the mode (r/w/a): ";
			cin>>mode;
			cout<<"\nEnter the View (Hidden (y/n) ): ";
			cin>>view;
			type_of_file="PARENT_DIRECTORY";
			size=0;
			struct tree* node=create_tree_node(mode,view,type_of_file,size,name);
			lev=1;
			add_to_tree(&root,node,lev);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		default:
			cout<<"Invalid! "
			return 0;
	}
	return 0;
}
