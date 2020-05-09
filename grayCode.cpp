#include<bits/stdc++.h>
using namespace std;

void greyCodeUtil(vector<int>& res, int n, int& num){
    if(n==0){
        res.push_back(num);
        return;
    }
    //ignore the bit
    greyCodeUtil(res,n-1,num);
    //invert the bit
    num=num^(1<<(n-1));
    greyCodeUtil(res,n-1,num);
}

vector<int> greyCode(int n){
    vector<int> res;
    int num=0;
    greyCodeUtil(res,n, num);
    return res;
}

int main(){
    int n=3;
    vector<int> code= greyCode(n);
    for(int i=0;i<code.size();i++)
        cout<<code[i]<<endl;
    return 0;
}