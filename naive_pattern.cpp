#include<bits/stdc++.h>
using namespace std;

void search(char *pat, char *txt){
    int N = strlen(pat);
    int M = strlen(txt);
    for(int i=0;i<M-N; i++){
        int j;
        for(j=0;j<N;j++){
            if(txt[i+j]!=pat[j])
                break;
        }
        if(j==N)
            cout<<"Pattern Present at Index "<<i<<endl;
    }
}

int main(){
    char txt[]="AABAACAADAABAAABAA";
    char pat[]="AABA";
    search(pat,txt);
    return 0;
}