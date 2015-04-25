 #include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* left;
	struct node* right;
};
struct node* createnode(int i){
	struct node *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=i;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
int isBTComplete(struct node* root)
{

if(root==NULL) return 0;

if((root->left && root->right && isBTComplete(root->left) && isBTComplete(root->right))
 ||(root->left &&root->right==NULL && isBTComplete(root->left)))
  return 1;

return 0;

}

int main(){
	struct node *root;
	root=createnode(1);
	root->left=createnode(2);
	root->right=createnode(3);
	//root->left->left=createnode(4);
	root->right->left=createnode(4);
	root->right->right=createnode(5);
	if(isBTComplete(root))
		printf("complete");
	else
		printf("not complete");
}
