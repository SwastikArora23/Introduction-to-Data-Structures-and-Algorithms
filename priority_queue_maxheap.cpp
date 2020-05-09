#include<bits/stdc++.h>
using namespace std;

void showpq(priority_queue <int> gq)
{
    priority_queue<int> g = gq;
    while(!g.empty()){
        cout<<"\t"<<g.top();
        g.pop();
    }
    cout<<"\n";
}

int main(){
    priority_queue<int> spz;
    spz.push(10);
    spz.push(30);
    spz.push(20);
    spz.push(5);
    spz.push(1);
    cout<<"The elements are: \n";
    showpq(spz);
    cout<<"\nthe Size is:"<<spz.size();
    cout<<"\n the top is:"<<spz.top();
    cout<<"\npopping an element";
    spz.pop();
    showpq(spz);
    return 0;
}
