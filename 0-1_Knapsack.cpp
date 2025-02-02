#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}

int knapsack(int m,int n,int p[],int wt[])
//here m=capacity , n=length , p=profit , wt = weight                                                                 
{                                                           
    int k[n+1][m+1];  //k[5][9]                             
                                                    
    for(int i=0;i<=n;i++)                                     
    {
        for(int w=0;w<=m;w++)
        {
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
            {
                k[i][w]=Max(k[i-1][w], p[i] + k[i-1][w - wt[i]]);  
            }
            else
                k[i][w]=k[i-1][w];
        }
    }
    return k[n][m];
}

int main()
{

    int profit[] = {0, 1, 2, 6, 5};
    int weight[] = {0, 2, 3, 4, 5};
    int n = 4;
    int capacity = 8;
    int maxP;
    maxP = knapsack(capacity, n, profit, weight);
    cout << "Max Profit: " << maxP << endl;
}