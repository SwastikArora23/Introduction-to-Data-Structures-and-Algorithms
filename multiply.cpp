#include<bits/stdc++.h>
using namespace std;

int multiply(int x, int y){
    if(y==0)
        return 0;
    if(y>0)
        return (x+multiply(x,y-1));
    if(y<0)
        return -multiply(x,-y);
}

int main(){
    cout<<multiply(5,-11);
    return 0;
}