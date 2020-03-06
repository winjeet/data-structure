#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

typedef struct p_queue
{
     char info;
     int prio;
     struct p_queue *link;
}node;
node *head;

void empt()
{
    head=NULL;
}

void enq()
{
    node *ptr,*loc,*temp;

    ptr=(node*)malloc(sizeof(node));
    cout<<"Enter value: ";
    cin>>ptr->info;
    cout<<"Enter Priority ";
    cin>>ptr->prio;
       if(head==NULL || head->prio>ptr->prio)
        {
          ptr->link=head;
          head=ptr;
        }
       else
        {
          loc=head;
           while(loc->prio<=ptr->prio && loc->link!=NULL)
            {
              temp=loc;
              loc=loc->link;
            }
           if(loc->prio>ptr->prio)
            {
              ptr->link=temp->link;
              temp->link=ptr;
            }
           else
            {
              loc->link=ptr;
              ptr->link=NULL;
            }
        }
}

void deq()
{
    node *ptr=head;
    cout<<"delete item : "<<ptr->info;
    head=ptr->link;
    free(ptr);
}

void traverse()
{
    node *ptr=head;
    if(head==NULL)
    {
        cout<<"underflow\n";
        return;
    }
    cout<<"   Item   Priority"<<endl;
    while(ptr!=NULL)
        {
           cout<<"    "<<ptr->info<<"        "<<ptr->prio<<endl;
           ptr=ptr->link;
        }

}

int main()
{
  empt();
  int s;
  do
  {
    cout<<"\n1 insert\n2 traverse\n3 delete\n4 exit\n";
    cout<<"Enter choise ";
    cin>>s;
      switch(s)
      {
        case 1: enq();
                break;
        case 2: traverse();
                break;
        case 3: deq();
                break;
        case 4:
                break;
        default:
                cout<<"Wrong value!!!\n";
                break;
      }
  }while(s!=4);


}

