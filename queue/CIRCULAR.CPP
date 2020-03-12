#include<iostream.h>
#include<conio.h>

que[5],front=-1,rear=-1;
void enq()
{
   if(front==0 && rear==4 ||front==rear+1)
   {
       cout<<"Overflow";
       return;
   }
   int item;
   cout<<"Enter Item: ";
   cin>>item;
   if(front==-1)
   {
       front=rear=0;
   }
   else if(rear==4)
   {
       rear=0;
   }
   else
   {
      rear=rear+1;
   }
   que[rear]=item;
}

void deq()
{
    if(front==-1)
    {
	cout<<"Underflow";
	return;
    }
    cout<<"Deleted item = "<<que[front]<<endl;
    if(front==rear)
    {
	front=rear=-1;
    }
    else if(front==4)
    {
	front=0;
    }
    else
    {
       front=front+1;
    }
}

void traverse()
{
   int i;
   if(front==-1)
   {
       cout<<"Underflow";
       return;
   }
   else
   {
     if(rear>=front)
     {
       for(i=front;i<=rear;i++)
       {
	  cout<<que[i]<<endl;
       }
     }
     else
     {
       for(i=front;i<=4;i++)
       {
	  cout<<que[i]<<endl;
       }
       for(i=0;i<=rear;i++)
       {
	  cout<<que[i]<<endl;
       }
     }
   }
}

void main()
{
    clrscr();
    int s;
    cout<<"1 Insert\n2 Delete\n3 Display\n4 Exit\n";
    do
    {
       cout<<"Enter your Choice: ";
       cin>>s;
       switch(s)
       {
	  case 1:
		 enq();
		 break;
	  case 2:
		 deq();
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
