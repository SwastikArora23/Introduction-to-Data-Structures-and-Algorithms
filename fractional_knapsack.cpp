#include<bits/stdc++.h>
using namespace std;

struct Item{
    int value, weight;
    Item(int value, int weight) : value(value), weight(weight) {} 
};

bool comp(struct Item a, struct Item b){
    double r1 = (double)a.value/a.weight;
    double r2 = (double)b.value/b.weight;
    return r1>r2;
}

double FractionalKnapsack(int W, struct Item arr[], int n){
    sort(arr, arr+n, comp);
    int CurWeight = 0;
    double finalValue = 0.0;
    for(int i=0;i<n;i++){
        if(CurWeight + arr[i].weight <= W){
            CurWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else{
            int remain = W- CurWeight;
            finalValue +=arr[i].value*((double)remain/arr[i].weight);
            break;
        }
    }
    return finalValue;
}

int main(){
    int W = 50;
    Item arr[]={{60,10},{100,20},{150,30}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<FractionalKnapsack(W, arr, n);
    return 0;
}