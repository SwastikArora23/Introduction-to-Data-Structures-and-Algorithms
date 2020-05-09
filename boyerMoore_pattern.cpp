#include<bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

void barCharHeuristic(string str, int size, int badChar[NO_OF_CHARS]){
    int i;
    for(i=0;i<NO_OF_CHARS;i++)
        badChar[i]=-1;
    
    for(i=0;i<size;i++)
        badChar[(int) str[i]]=i;
}

void search(string pat, string txt){
    int m=pat.size();
    int n=txt.size();
    int badChar[NO_OF_CHARS];

    barCharHeuristic(pat, m, badChar);

    int s=0;

    while(s<=(n-m)){
        int j=m-1;
        while(j>=0 && pat[j]==txt[s+j]){
            j--;
        }
        if(j>0){
            cout<<"Pattern occurs at shift "<<s<<endl;
            s+=(s+m < n) ? m-badChar[txt[s+m]] : 1;
        }
        else{
            s+=max(1, j-badChar[txt[s+j]]);
        }
    }
}

int main(){
    string txt="ABAAABCD";
    string pat="ABC";
    search(pat,txt);
    return 0;
}