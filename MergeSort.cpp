#include<iostream>
#include<stdlib.h>

using namespace std;

void Merge(int*,int,int,int);
void MergeSort(int*,int,int);

int main()
{  int arr[20],n,i;
   system("cls");
   cout<<"\nEnter the Array size(max: 20):";
   cin>>n;
   cout<<"\nEnter the elements of Array:";
   for(i=0;i<n;i++)
 { cin>>arr[i];  }
    MergeSort(arr,0,n-1);
    cout << "\nSorted array is: ";
    for(i=0;i<n;i++)
 {  cout<<arr[i]<<  " ";  }
   // getch();
    return 0;
 }
void MergeSort(int arr[],int low,int high){
    if(low>=high)
    { return;    }
    int mid = (low+high-1)/2;
    MergeSort(arr,low,mid);
    MergeSort(arr,mid+1,high);
    Merge(arr,low,mid,high);
}
void Merge(int arr[], int low, int mid, int high)
{   int L[10],R[10];
    int a1 = mid - low + 1;
    int a2 = high - mid;
    for (int x = 0; x < a1; x++)
     {	L[x] = arr[low + x];  }
    for (int y = 0; y < a2; y++)
     {	R[y] = arr[mid + 1 + y];}
    int i=0,j=0,k=low;
    while (i < a1 && j < a2){
	if (L[i] <= R[j]) {
	    arr[k] = L[i];
	    i++;   }
	else {
	    arr[k] = R[j];
	    j++;  }
	k++;  
   }
    while (i < a1) {
	arr[k] = L[i];
	i++; 
	k++;
    }  
    while (j < a2) {
	arr[k] = R[j];
	j++;
	k++;
    }
}
