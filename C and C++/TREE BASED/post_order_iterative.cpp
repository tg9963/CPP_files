// C program for iterative postorder traversal using one stack
#include <stdio.h>
#include <stdlib.h>
 
// Maximum stack size
#define MAX_SIZE 100
 
// A tree node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// Stack type
struct Stack
{
    int size;
    int top;
    struct Node* *array;
};
 
// A utility function to create a new tree node
struct Node* newNode(int data)
{
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// A utility function to create a stack of given size
struct Stack* createStack(int size)
{
    struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
    stack->size = size;
    stack->top = -1;
    stack->array = (struct Node**) malloc(stack->size * sizeof(struct Node*));
    return stack;
}
 
// BASIC OPERATIONS OF STACK
int isFull(struct Stack* stack)
{  return stack->top - 1 == stack->size; }
 
int isEmpty(struct Stack* stack)
{  return stack->top == -1; }
 
void push(struct Stack* stack, struct Node* node)
{
    if (isFull(stack))
        return;
    stack->array[++stack->top] = node;
}
 
struct Node* pop(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
 
struct Node* peek(struct Stack* stack)
{
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
void postOrderIterative(struct Node* root)
{
	if(root==NULL)return ;
	struct Stack* s=createStack(10);
	do
	{
		while(root)
		{
			if(root->right)push(s,root->right);
			push(s,root);
			root=root->left;
		}
		root=pop(s);
		if(root->right && root->right==peek(s))
		{
			pop(s);
			push(s,root);
			root=root->right;
		}
		else
		{
			printf("%d->",root->data);
			root=NULL;
		}
	}while(!isEmpty(s));
}
int main()
{
    // Let us construct the tree shown in above figure
    struct Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
 
    postOrderIterative(root);
 
    return 0;
}

