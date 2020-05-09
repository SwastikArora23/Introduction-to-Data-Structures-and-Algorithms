#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b) ? a : b;
}

int Knapsack(int W, int wt[], int value[], int n){
    int i,j;
    int K[n+1][W+1];
    for(i=0;i<=n;i++){
        for(j=0;j<=W;j++){
            if(i==0 || j==0)
                K[i][j] = 0;
            else if(wt[i-1]<=j)
                K[i][j] = max(value[i-1]+K[i-1][j-wt[i-1]], K[i-1][j]);
            else
                K[i][j] = K[i-1][j];
        }
    }
    return K[n][W];
}

int main(){
    int val[]={60,100,150};
    int wt[] ={10,20,30};
    int W = 50;
    int n =sizeof(val)/sizeof(val[0]);
    cout<<Knapsack(W,wt,val,n);
    return 0;
}