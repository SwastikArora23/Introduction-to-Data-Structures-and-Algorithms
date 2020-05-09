#include<bits/stdc++.h>
using namespace std;

void showpq(priority_queue<int, vector<int>, greater<int>>gr)
{
    priority_queue<int, vector<int>, greater<int>> h = gr;
    while(!h.empty()){
        cout<<"\t"<<h.top();
        h.pop();
    }
    cout<<"\n";
}

int main(){
    priority_queue<int, vector<int>, greater<int>> spk;
    spk.push(10);
    spk.push(30);
    spk.push(20);
    spk.push(5);
    spk.push(1);
    spk.push(0);
    cout<<"The Priority Queue is:\n";
    showpq(spk);
    cout<<"\n the Size is:"<<spk.size();
    cout<<"\n the top is:"<<spk.top();
    cout<<"\nPoppin the element";
    spk.pop();
    showpq(spk);
    return 0;
}