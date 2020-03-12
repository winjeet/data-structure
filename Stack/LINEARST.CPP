#include<iostream.h>
#include<conio.h>

int stack[5],top=-1;

void push()
{
    if(top==4)
    {
       cout<<"Overflow"<<endl;
       return;
    }
    int item;
    cout<<"Enter item: ";
    cin>>item;
    top=top+1;
    stack[top]=item;
}

void pop()
{
    if(top==-1)
    {
       cout<<"Underflow"<<endl;
       return;
    }
    cout<<"Deleted item = "<<stack[top]<<endl;
    top=top-1;
}

void traverse()
{
    int i;
    if(top==-1)
    {
       cout<<"Underflow"<<endl;
       return;
    }
    for(i=0;i<=top;i++)
    {
       cout<<stack[i]<<endl;
    }
}

void main()
{
   clrscr();
   int s;
   cout<<"1 PUSH\n2 POP\n3 DISPLAY\n4 EXIT\n";
   do
   {
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