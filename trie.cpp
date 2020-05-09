#include<bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndofWord;
};

struct TrieNode *getNode(){
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndofWord = false;
    for(int i=0;i<ALPHABET_SIZE;i++)
        pNode->children[i] =NULL;
    
    return pNode;
}

void insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    for(int i=0;i<key.length();i++){
        int index= key[i]-'a';
        if(!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        
        pCrawl = pCrawl->children[index];
    }
    pCrawl->isEndofWord = true;
}

bool search(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    for(int i=0;i<key.length();i++){
        int index= key[i]-'a';
        if(!pCrawl->children[index])
            return false;
        
        pCrawl= pCrawl->children[index];
    }
    return (pCrawl!=NULL && pCrawl->isEndofWord);
}

bool isEmpty(TrieNode *root){
    for(int i=0;i<ALPHABET_SIZE;i++)
        if(root->children[i])
            return false;
    return true;
}

TrieNode *remove(TrieNode *root, string key, int depth = 0){
    if(!root)
        return NULL;
    if(depth == key.size()){
        if(root->isEndofWord)
            root->isEndofWord = false;
        
        if(isEmpty(root)){
            delete(root);
            root = NULL;
        }

        return root;
    }
    int index = key[depth]-'a';
    root->children[index] = remove(root->children[index], key, depth+1);
    if(isEmpty(root) && root->isEndofWord == false)
    {
        delete(root);
        root=NULL;
    }
    return root;
}

int main(){
    string keys[]={"the","a","there","answer","any","by","bye","their"};
    int n =sizeof(keys)/sizeof(keys[0]);
    struct TrieNode *root = getNode();
    for(int i=0;i<n;i++)
        insert(root, keys[i]);

    search(root,"the")? cout<<"YES\n" : cout<<"NO\n";
    search(root,"these")? cout<<"YES\n" : cout<<"NO\n";
    
    remove(root, "their");
    search(root, "the") ? cout<<"YES\n" : cout<<"NO\n";
    
    return 0; 
}