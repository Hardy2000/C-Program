
#include<iostream.h>
#include<conio.h>
int bsearch( int[],int,int);
int main()
{ int ar[50],item,n,index;
   clrscr();
   cout<<"\nEnter the array size: ";
 cin>>n;
cout<<"\nEnter the array elements:\n";
for(int i=0;i<n;i++)
 cin>>ar[i];
cout<<"\nEnter the element to be searched for:";
cin>>item;
index=bsearch(ar,n,item);
if(index==-1)
cout<<"\nGiven element doesn't exist.";
else cout<<"\nElement found at index: "<<index<<", Position: "<<index+1<<endl;
return 0;
}
int bsearch(int ar[],int size, int item)
{ int beg=0,last=size-1,mid;
  while(beg<=last)
 { mid=(beg+last)/2;
   if(item==ar[mid])  return mid;
   else if(item>ar[mid])   beg=mid+1;
   else last=mid-1;
}
return -1;
}