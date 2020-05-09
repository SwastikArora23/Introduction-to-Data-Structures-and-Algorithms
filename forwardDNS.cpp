#include<bits/stdc++.h>
using namespace std;
#define CHARS 27
#define MAX 100

int getIndex(char c){
    return (c=='.')?26:(c-'a');
}
char getCharChildIndex(int i){
    return (i==26)? '.':('a'+i); 
}

struct TrieNode{
    bool isLeaf;
    char *ipAdd;
    struct TrieNode *children[CHARS];
};

struct TrieNode *newTrieNode(){
    struct TrieNode *newNode = new TrieNode;
    newNode->isLeaf = false;
    newNode->ipAdd = NULL;
    for(int i=0;i<CHARS;i++){
        newNode->children[i]=NULL;
    }
    return newNode;
}

void insert(struct TrieNode *root, char *URL, char *ipAdd){
    int len = strlen(URL);
    struct TrieNode *pNode = root;
    for(int level=0;level<len;level++){
        int index = getIndex(URL[level]);
        if(!pNode->children[index])
            pNode->children[index]=newTrieNode();
        pNode= pNode->children[index];
    }
    pNode->isLeaf = true;
    pNode->ipAdd = new char[strlen(ipAdd)+1];
    strcpy(pNode->ipAdd, ipAdd);
}

char *searchDNSCache(struct TrieNode *root, char *URL){
    struct TrieNode *pNode = root;
    int len = strlen(URL);
    for(int level=0;level<len;level++){
        int index = getIndex(URL[level]);
        if(!pNode->children[index])
            return NULL;
        pNode=pNode->children[index];
    } 
    if(pNode!=NULL && pNode->isLeaf)
        return pNode->ipAdd;
    return NULL;
}

int main(){
    char URL[][50] = {"www.samsung.com","www.samsung.net","www.google.in"};
    char ipAdd[][MAX] = {"107.108.11.123","107.109.123.255","74.125.200.106"};
    int n = sizeof(URL)/sizeof(URL[0]);
    struct TrieNode *root = newTrieNode();
    for(int i=0;i<n;i++){
        insert(root, URL[i], ipAdd[i]);
    }
    char url[]="www.samsung.com";
    char *res_ip = searchDNSCache(root, url);
    if(res_ip!=NULL){
        cout<<"FORWARD DNS CACHE IP ADDRESS: "<<url<<"-->"<<res_ip;
    }
    else{
        cout<<"IP ADDRESS NOT FOUND";
    }
    return 0;
}