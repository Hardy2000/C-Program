#include <iostream>
using namespace std;

int max(int,int);
int knapSack(int,int*,int*,int); 

int main() 
{
int num, weight,v[10],w[10];
cout<<"Enter the number of items in a Knapsack : ";
cin>>num;
cout<<"Enter the capacity of Knapsack : ";
cin>>weight;
cout<<"\nEnter the weight profit of following Items:\n";
for(int i=0;i<num;i++)
{
cout<<"\n=============================Item "<<i+1<<"====================================\n";
cout<<"Weight:";
cin>>w[i];
cout<<"Profit :";
cin>>v[i];
}
int p=knapSack(weight,w,v,num);
   cout<<"Knapsack value is : "<<p<<"\n";
   return 0;
}

int knapSack(int W, int w[], int v[],int n) 
{
   int i, wt;
   int K[n + 1][W + 1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= W; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   int total=K[n][W];
   return total;
}

int max(int x, int y) 
{
   return (x > y) ? x : y;
}
