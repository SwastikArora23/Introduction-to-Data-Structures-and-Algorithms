#include<bits/stdc++.h>
using namespace std;

float squareRoot(float n){
    float x=n;
    float y=1;
    float e=0.000001;
    while(x-y>e){
        x=(x+y)/2;
        y=n/x;
    }
    return x;
}

int main(){
    int n=50;
    cout<<"SQUARE ROOT FOR "<<n<<" = "<<squareRoot(n);
    return 0;
}