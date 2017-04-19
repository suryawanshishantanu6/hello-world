#include <iostream>
#include <string.h>
#define max 50
using namespace std;

class node
{
	public:
		node *left,*right;
		char data;
};

class exptree
{
	public:
		char post[max];
		node *arr[max];
		int top;
		node *root;		
		exptree()
		{
			top=-1;
			root=NULL;
		}
		void push(node *);
		node *pop();
		node *create_tree(char []);
		int check(char);
		void postorder(node *);		
};

void exptree :: push(node *p)
{
	top++;
	arr[top]=p;
}

node *exptree :: pop()
{
	return (arr[top--]);
}

int exptree :: check(char symbol)
{
	if(symbol=='+' || symbol=='-' || symbol=='*' || symbol=='/' || symbol=='^')
		return 1;
	return 0;
}

node *exptree :: create_tree(char post[])
{
	node *temp, *ptr1, *ptr2;
	int i;
	for(i=0;i<strlen(post);i++)
	{
		if(!check(post[i]))			//operand
		{
			temp=new node;
			temp->data=post[i];
			temp->left=NULL;
			temp->right=NULL;
			push(temp);			
		}
		else
		{
			temp=new node;
			temp->data=post[i];
			temp->left=NULL;
			temp->right=NULL;			
			ptr1=pop();
			ptr2=pop();
			temp->left=ptr2;
			temp->right=ptr1;
			push(temp);
		}
	}
	temp=pop();
	return temp;
}

void exptree :: postorder(node *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}

int main()
{
	exptree e;
	char post[max];
	node *p;
	cout<<"\nEnter a postfix expression: ";
	cin>>post;
	p=e.create_tree(post);
	cout<<"\nPost-order: ";
	e.postorder(p);
	return 0;
	
}



