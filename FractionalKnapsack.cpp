#include<iostream>
#include<stdlib.h>

using namespace std;

 int knapsack(int a[2][100],int n,int w) 
{  int  i,c, used[100], max = -1, profit = 0;
    
    
        for (i = 0; i < n; i++)
    {
        used[i] = 0;
    }
    c = w;
    while (c >= 0)
    {
        max = -1;
        for (i = 0; i < n; i++)
        {
            if ((used[i] == 0) && ((max == -1) || (((float) a[1][i]
                    / (float) a[0][i]) > ((float) a[1][max]
                    / (float) a[0][max]))))
            {
                max = i;
            }
        }
        used[max] = 1;
        c -= a[0][max];
        profit += a[1][max];
        if (c >= 0)
        {
            cout << "\n\nAdded item " << max + 1 << "\n Weight: "
                    << a[0][max] << "\t Profit: " << a[1][max]
                    << "\n Space left: " << c;
        }
        else
        {
            cout << "\n\nAdded item " << max + 1 << "\n Weight: "
                    << (a[0][max] + c) << "\t Profit: "
                    << (a[1][max] / a[0][max]) * (a[0][max]
                            + c) << " \n Space left: 0";

            profit -= a[1][max];
            profit += ((a[1][max] / a[0][max]) * (a[0][max]
                    + c));
        }
    }
     return profit;
}


int main()
{   
    int a[2][100], num, weight;
    system("cls");
    cout << "Enter number of objects: ";
    cin >> num;
    cout << "Enter the weight of the knapsack: ";
    cin >> weight;
  
cout<<"\nEnter the weight profit of following Items:\n";
for(int i=0;i<num;i++)
{
cout<<"\n=============================Item "<<i+1<<"====================================\n";
cout<<"Weight:";
cin>>a[0][i];
cout<<"Profit :";
cin>>a[1][i];
}
int p=knapsack(a,num,weight);
cout << "\nTotal Profit: " << p<<"\n";
return 0;
       
}

