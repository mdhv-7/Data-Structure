#include<stdio.h>
#define MAX 10
int stack[MAX];
int top=-1;
void push(int item)
{
if(top==MAX-1)
{
printf("\n stack overflow!");
return;
}
stack[++top]=item;
printf("\n %d pushed to stack",item);
}
void pop()
{
if(top==-1)
{
printf("\n stack underflow!");
return;
}
printf("\n %d popped from stack",stack[top--]);
}
void peek()
{
if(top==-1)
{
printf("stack is empty");
return;
}
printf("\n Top element is %d",stack[top]);
}
void display()
{
if(top==-1)
{
printf("\n stack is empty");
return;
}
printf("stack elements are:");
for(int i=top;i>=0;i--)
{
printf("%d",stack[i]);
}
}
int main()
{
int choice,value;
while(1)
{
printf("stack operations menu");
printf("\n 1.Push");
printf("\n 2.Pop");
printf("\n 3.Peek");
printf("\n 4.Display");
printf("\n 5.Exit");
printf("\n Enter choice");
scanf("%d",&choice);
switch(choice)
{
case 1:printf("\n enter value to push");
scanf("%d",&value);
push(value);
break;
case 2:pop();
break;
case 3:peek();
break;
case 4:display();
break;
case 5:printf("Exiting program");
return 0;
default:printf("\n invalid choice!");
}
}
}




