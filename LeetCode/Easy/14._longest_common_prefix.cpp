#include <iostream>
#include <vector>
using namespace std;

class Trie{
    public:
    Trie*children[26];
    bool isEnd;
    int links=0;
    
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
            if(t->children[idx]==nullptr){t->children[idx]=new Trie();t->links++;}
            t=t->children[idx];
        }
        t->isEnd=true;
    }
};


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        Trie* root = new Trie();
        for (string word : strs) {
            root->insert(word);
        }

        string res;
        Trie* t = root;

        while (t && t->links == 1 && !t->isEnd) {
            for (int i = 0; i < 26; i++) {
                if (t->children[i] != nullptr) {
                    res.push_back('a' + i);
                    t = t->children[i];
                    break;
                }
            }
        }
        return res;
    }
};