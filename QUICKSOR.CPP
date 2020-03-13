#include<iostream.h>
#include<conio.h>

int l[20]={-1},l_top=0,u[20],u_top=-1;

int empty()
{
   if(l[l_top]==-1)
   {
      return 0;
   }
   else
   {
   return 1;
   }
}
void push_l(int item)
{
   if(l_top==-1)
   {
      l_top=0;
   }
   else
   {
      l_top=l_top+1;
   }
   l[l_top]=item;
}
void push_u(int item)
{
   if(u_top==-1)
   {
      u_top=0;
   }
   else
   {
      u_top=u_top+1;
   }
   u[u_top]=item;
}
int pop_l()
{
   int t;
   t=l[l_top];
   l_top=l_top-1;
   return t;
}
int pop_u()
{
   int t;
   t=u[u_top];
   u_top=u_top-1;
   return t;
}

int quick(int a[],int beg,int end)
{
   int left,right,loc;
   left=loc=beg;
   right=end;
   s:
   while(a[loc]<=a[right] && loc!=right)
   {
      right=right-1;
   }
   if(loc==right)
   {
      return(loc);
   }
   if(a[loc]>a[right])
   {
	int t;
	t=a[loc];
	a[loc]=a[right];
	a[right]=t;
	loc=right;
   }
   while(a[left]<=a[loc] && left!=loc)
   {
      left=left+1;
   }
   if(loc==left)
   {
      return(loc);
   }
   if(a[left]>a[loc])
   {
      int t;
      t=a[left];
      a[left]=a[loc];
      a[loc]=t;
      loc=left;
      goto s;
   }
}
void quick_s(int a[],int n)
{
   int beg,end;
   if(n>0)
   {
      push_l(0);
      push_u(n-1);
   }
   while(empty())
   {
      beg=pop_l();
      end=pop_u();

      int loc = quick(a,beg,end);
      if(beg<loc-1)
      {
	 push_l(beg);
	 push_u(loc-1);
      }
      if(loc+1<end)
      {
	 push_l(loc+1);
	 push_u(end);
      }
   }
}

void main()
{
   clrscr();
   int a[20],n,i;
   cout<<"Enter size of array: ";
   cin>>n;
   cout<<"Enter element ";
   for(i=0;i<n;i++)
   {
      cin>>a[i];
   }
   quick_s(a,n);
   cout<<"After sorting\n";
   for(i=0;i<n;i++)
   {
      cout<<a[i]<<endl;
   }
 getch();
}


