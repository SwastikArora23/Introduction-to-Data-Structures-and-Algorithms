#include<bits/stdc++.h>
using namespace std;

#define CHARS 11

#define MAX 50

int getIndex(char c){
    return (c=='.')? 10 : (c-'0');
}
char getCharfromChildIndex(int i){
    return (i==10)? '.' : ('0'+i);
}

struct TrieNode{
    bool isLeaf;
    char *URL;
    struct TrieNode *children[CHARS];
};

struct TrieNode *newTrieNode(){
    struct TrieNode *newNode = new TrieNode;
    newNode->isLeaf = false;
    newNode->URL = NULL;
    for(int i=0;i<CHARS;i++)
        newNode->children[i]=NULL;
    return newNode;
}

void insert(struct TrieNode *root, char *ipAdd, char *URL){
    int len = strlen(ipAdd);
    struct TrieNode *pNode = root;

    for(int level = 0; level< len; level++){
        int index = getIndex(ipAdd[level]);
        if(!pNode->children[index])
            pNode->children[index] = newTrieNode();
        pNode = pNode->children[index];
    }
    pNode->isLeaf = true;
    pNode->URL = new char[strlen(URL) + 1];
    strcpy(pNode->URL, URL);
}

char *searchDNSCache(struct TrieNode *root, char *ipAdd){
    struct TrieNode *pNode = root;
    int len = strlen(ipAdd);
    for(int i=0;i<len; i++){
        int index = getIndex(ipAdd[i]);
        if(!pNode->children[index])
            return NULL;
        pNode = pNode->children[index];
    }
    if(pNode!=NULL && pNode->isLeaf)
        return pNode->URL;
    return NULL;
}

int main(){
    char ipAdd[][MAX]={"107.108.11.123","107.109.123.255","74.125.200.106"};
    char URL[][50] ={"www.samsung.com","www.samsung.net","www.google.in"};
    int n = sizeof(ipAdd)/sizeof(ipAdd[0]);
    struct TrieNode *root = newTrieNode();
    for(int i=0;i<n;i++)
        insert(root, ipAdd[i], URL[i]);
    char ip[]="107.108.11.123";
    char *res_url = searchDNSCache(root, ip);
    if(res_url!=NULL){
        cout<<"REVERSE DNS URL IS: "<<ip<<"-->"<<res_url;
    } 
    else{
        cout<<"REVERSE DNS CACHE NOT RESOLVED";
    }
    return 0;
}