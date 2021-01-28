
#include<iostream.h>
#include<conio.h>

int partition (int*,int,int);
void QuickSort(int*,int,int);
int main()
{  int arr[20],n,i;
   clrscr();
   cout<<"\nEnter the Array size(max:20):";
   cin>>n;
   cout<<"\nEnter the elements of Array:";
   for(i=0;i<n;i++)
   { cin>>arr[i];
   }
    QuickSort(arr,0,n-1);
    cout << "\nSorted array: \n";
    for (i=0;i<n; i++)
  { cout << arr[i] << " ";   }
    getch();
    return 0;

}
void QuickSort(int arr[], int low, int high)
{
    if (low < high)
    {
	int pi = partition(arr, low, high);
	QuickSort(arr, low, pi - 1);
	QuickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high)
{

    int pivot=arr[high],temp;
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {	if (arr[j] < pivot)
    {   i++;
	int temp=arr[i];
	arr[i]=arr[j];
	  arr[j]=temp;

	}

    }
    temp=arr[i+1];
	  arr[i+1]=arr[high];
	  arr[high]=temp;
   return (i + 1);
}
