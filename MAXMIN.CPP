#include<iostream.h>
#include<conio.h>

void main()
{int a[20],n,i,max,min;;
clrscr();
cout<<"\nEnter the size of the Array:";
cin>>n;
cout<<"\nEnter the elements of Array:";
for(i=0;i<n;i++)
{ cin>>a[i];
 }
max,min=a[0];
for(i=1;i<n;i++)
{ if(a[i]>max)
   max=a[i];
  if(a[i]<min)
   min=a[i];  }
cout<<"\nMaximum element:"<<max<<"\nMinimum element:"<<min;
getch();

}