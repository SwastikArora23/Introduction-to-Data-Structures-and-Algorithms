#include<bits/stdc++.h>
using namespace std;
int term[1000];
int fib(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    if(term[n]!=0)
        return term[n];
    else 
        term[n] = fib(n-1)+fib(n-2);
        return term[n];
}

int main(){
    int n=6;
    cout<<fib(n);
    return 0;
}