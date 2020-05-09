#include<bits/stdc++.h>
using namespace std;

int swapNibble(int x){
    return ((x& 0x0F) <<4 | (x&0xF0) >> 4);
}

int main(){
    int x=100;
    cout<<swapNibble(x);
    return 0;
}