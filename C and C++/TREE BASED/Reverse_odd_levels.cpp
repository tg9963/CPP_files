#include<iostream>
#include<queue>

using namespace std;
 
// A Binary Tree node
struct Node
{
    char data;
    struct Node *left, *right;
    Node(char _data):data(_data),left(NULL),right(NULL){}
};
 
void level(Node *root)
{
   queue<Node*> q;
   q.push(root);
   int n=0;
   while(q.size())
   {
      n=q.size();
      while(n--)
      {
         root=q.front();
         q.pop();
         cout<<root->data<<" ";
         if(root->left)q.push(root->left);
         if(root->right)q.push(root->right);
      }
      cout<<"\n";
   }
}

void swap(char &a, char &b)
{
   a^=b;
   b^=a;
   a^=b;
}

void reverse(Node *l, Node *r, int level)
{
   if(!l || !r)return;
   if(level%2)swap(l->data,r->data);
   reverse(l->left,r->right,level+1);
   reverse(l->right,r->left,level+1);
}

void rev(Node *root)
{
   if(!root)return;
   reverse(root->left,root->right,1);
}

int main()
{
    // Level 0
    struct Node *root = new Node('a');
    
    // Level 1
    root->left = new Node('b');
    root->right = new Node('c');

    // Level 2
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');

    // Level 3
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    // Level 4
    root->left->left->left->left = new Node('a');
    root->left->left->left->right = new Node('b');
    root->left->left->right->left = new Node('c');
    root->left->left->right->right = new Node('d');
    root->left->right->left->left = new Node('e');
    root->left->right->left->right = new Node('f');
    root->left->right->right->left = new Node('g');
    root->left->right->right->right = new Node('h');
    root->right->left->left->left = new Node('i');
    root->right->left->left->right = new Node('j');
    root->right->left->right->left = new Node('k');
    root->right->left->right->right = new Node('l');
    root->right->right->left->left = new Node('m');
    root->right->right->left->right = new Node('n');
    root->right->right->right->left = new Node('o');
    root->right->right->right->right = new Node('p');
    

    // Level 5
    root->left->left->left->left->left = new Node('a');
    root->left->left->left->left->right = new Node('A');
    root->left->left->left->right->left = new Node('b');
    root->left->left->left->right->right = new Node('B');
    root->left->left->right->left->left = new Node('c');
    root->left->left->right->left->right = new Node('C');
    root->left->left->right->right->left = new Node('d');
    root->left->left->right->right->right = new Node('D');
    root->left->right->left->left->left = new Node('e');
    root->left->right->left->left->right = new Node('E');
    root->left->right->left->right->left = new Node('f');
    root->left->right->left->right->right = new Node('F');
    root->left->right->right->left->left = new Node('g');
    root->left->right->right->left->right = new Node('G');
    root->left->right->right->right->left = new Node('h');
    root->left->right->right->right->right = new Node('H');
    root->right->left->left->left->left = new Node('i');
    root->right->left->left->left->right = new Node('I');
    root->right->left->left->right->left = new Node('j');
    root->right->left->left->right->right = new Node('J');
    root->right->left->right->left->left = new Node('k');
    root->right->left->right->left->right = new Node('k');
    root->right->left->right->right->left = new Node('l');
    root->right->left->right->right->right = new Node('L');
    root->right->right->left->left->left = new Node('m');
    root->right->right->left->left->right = new Node('M');
    root->right->right->left->right->left = new Node('n');
    root->right->right->left->right->right = new Node('N');
    root->right->right->right->left->left = new Node('o');
    root->right->right->right->left->right = new Node('O');
    root->right->right->right->right->left = new Node('p');
    root->right->right->right->right->right = new Node('P');
    
    cout << "Level Traversal of given tree\n";

    level(root);
    rev(root);
    level(root);
    return 0;
}
