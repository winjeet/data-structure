#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

typedef struct stack
{
   int info;
   struct stack *link;
}node;
node *top;

void empty()
{
   top=NULL;
}

void push()
{
   node *ptr;
   ptr=(node*)malloc(sizeof(node));

   cout<<"Enter item: ";
   cin>>ptr->info;

      if(top==NULL)
      {
	 top=ptr;
	 ptr->link=NULL;
      }
      else
      {
	 ptr->link=top;
	 top=ptr;
      }
}

void pop()
{
   node *ptr=top;
   if(top==NULL)
   {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   {
      cout<<"Deleted item = "<<ptr->info<<endl;
      top=ptr->link;
      free(ptr);
   }
}

void traverse()
{
   node *ptr=top;
   if(top==NULL)
   {
      cout<<"Underflow"<<endl;
      return;
   }
   else
   {
      while(ptr!=NULL)
      {
	 cout<<ptr->info<<endl;
	 ptr=ptr->link;
      }
   }
}

void main()
{
   clrscr();
   empty();
   int s;
   do
   {
      cout<<"1 PUSH\n2 POP\n3 DISPLAY\n4 EXIT\n";
      cout<<"Enter your choice: ";
      cin>>s;
	 switch(s)
	 {
	    case 1:
		   push();
		   break;
	    case 2:
		   pop();
		   break;
	    case 3:
		   traverse();
		   break;
	    case 4:
		   break;
	 }
   }while(s!=4);
  getch();
}