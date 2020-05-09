#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE = 26;

struct Trie{
    int index;
    Trie *children[ALPHABET_SIZE];
    Trie(){
        for(int i=0;i<ALPHABET_SIZE;i++)
            children[i] = NULL;
        index = -1;
    }
};

void insert(Trie *root, string key, int index){
    Trie *node = root;
    for(int i=0;i<key.size();i++)
    {
        char ind = key[i]-'a';
        if(!node->children[ind])
            node->children[ind] = new Trie();

        node = node->children[ind];
    }    
    node->index = index;
}

bool preOrder(Trie *node, string arr[]){
    if(node == NULL)
        return false;
    
    for(int i=0;i<ALPHABET_SIZE;i++){
        if(node->children[i] != NULL){
            if(node->children[i]->index != -1)
                cout<<arr[node->children[i]->index]<<endl;
            preOrder(node->children[i],arr);
        }
    }
}

void printSorted(string arr[], int n){
    Trie *root = new Trie();
    for(int i=0;i<n;i++){
        insert(root,arr[i],i);
    }
    preOrder(root, arr);
}

int main(){
    string arr[]={"abc" ,"xyz", "bcd"};
    int n=sizeof(arr)/sizeof(arr[0]);
    printSorted(arr,n);
    return 0;
}
