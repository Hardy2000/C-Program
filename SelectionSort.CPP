#include<iostream.h>
#include<conio.h>

void sort(int a[],int size)
{ int small,pos,temp;
for(int i=0;i<size-1;i++)
{small=a[i];
pos=i;
for(int j=i+1;j<size;j++)
{ if(a[j]<small)
{small=a[j];pos=j;}
}
temp=a[i];
a[i]=a[pos];
a[pos]=temp;
cout<<"\nArray after pass-"<<i+1<<"-is:";
for(j=0;j<size;j++)
cout<<a[j]<<" ";

} }
void main()
{ clrscr();
int a[20],item,n,index;
cout<<"Enter the size of the array:";
cin>>n;
cout<<"Entar array elements:";
for(int i=0;i<n;i++)
cin>>a[i];
sort(a,n);
cout<<"\nThe sorted array is shown below:";
for(i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<endl;
}