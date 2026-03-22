#include <iostream>
using namespace std;

class Trie {
public:
Trie *children[26];
    bool isEnd;

    Trie() {
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isEnd=false;
    }
    
    void insert(string word) {
        Trie* t=this;
        for(char ch:word){
            int idx=ch-'a';
            if(t->children[idx]==nullptr)t->children[idx]=new Trie();
            t=t->children[idx];
        }
        t->isEnd=true;
    }
    
    bool search(string word) {
        Trie* t=this;
        for(char ch:word){
            int idx=ch-'a';
            if(t->children[idx]==nullptr)return false;
            t=t->children[idx];
        }
        return t->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie *t=this;
        for(char ch:prefix){
            int idx=ch-'a';
            if(t->children[idx]==nullptr)return false;
            t=t->children[idx];
        }
        return true;
    }
};


