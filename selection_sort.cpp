#include<iostream>
using namespace std;

void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    //One by one move the boundary of unsorted subarray
    for(i =0; i<n-1;i++){
        min_idx=i;
        for(j= i+1;j<n;j++)
        if(arr[j]<arr[min_idx])
            min_idx=j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int arr[]={65,25,12,11,22};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}