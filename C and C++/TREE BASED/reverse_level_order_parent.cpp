//http://www.geeksforgeeks.org/flipkart-interview-set-8-sde-1/

#include "iostream"
using namespace std;

class node
{
    public:
    int data;
    node *left,*right,*parent;
    int sum;
    node()
    {
        left=NULL;
        right=NULL;
        parent=NULL;
    }
};

node* newNode(int d)
{
    node *nd=new node();
    nd->data=d;
    return nd;
}
void assignParent(node *root)
{
    if(root==NULL) return;
    if(root->left !=NULL)
    root->left->parent=root;
    if(root->right!=NULL)
    root->right->parent=root;
    assignParent(root->left);
    assignParent(root->right);
}

void insert(node* root,int inputData,int a[])
{
    if(root==NULL) return ;
    if(root->data==a[inputData])
    {
        if(root->left)
        {
            root->right=newNode(inputData);
           // cout<<root->right->data<<endl;
        }
        else
        {
            root->left=newNode(inputData);
          //  cout<<root->left->data<<endl;
        }
        return;
    }
    insert(root->left,inputData,a);
    insert(root->right,inputData,a);
    return ;
}
int max(int a,int b)
{
    return a>b?a:b;
}

int height(node *root)
{
    if(root==NULL) return 0;
    return (max(height(root->left),height(root->right))+1);
}

void printEachLevel(node* root,int h);
void printLevelorder(node* root)
{
    for(int i=height(root);i>0;i--)
    {
        printEachLevel(root,i);
        cout<<endl;
    }
}

void printEachLevel(node* root,int h)
{
    if(root==NULL) return;
    if(h==1) cout<<root->data<<" ";
    else
    {
        printEachLevel(root->left,h-1);
        printEachLevel(root->right,h-1);
    }
}

int  main()
{
    int a[]={-1,0,0,1,1};
    int n=sizeof(a)/sizeof(a[0]);

    node* root=newNode(0);
   // cout<<root->data<<endl;
    for(int i=1;i<n;i++)
    {
        insert(root,i,a);
    }
    printLevelorder(root);
}
