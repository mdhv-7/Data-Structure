#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* link;
};
struct node *top=NULL;
void push()
{
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof (struct node));
	if(newnode==NULL)
	{
		printf("\n NO SPACE AVAILABLE \n");
		return;
	}
	newnode->link=NULL;
	printf("\n Enter the element to insert \n");
	scanf("%d",&newnode->data);
	if(top==NULL)
	{
   	   top=newnode
	}
	else
	{
 	  newnode->link=top;
	  top=newnode;
	}
	printf("\n %d INSERTED SUCCESSFULLY",newnode->data);
}
void pop()
{	
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\n stack underflow");
		return;
	}
	printf("\n %d is popped",temp->data);
	top=temp->link;
	free(temp);
}
void diaplay()
{
	struct node *temp=top;
	if(top==NULL)
	{
		printf("\n NO ELEMENTS");
		return;
	}
	     

