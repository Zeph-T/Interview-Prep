#include"trie.h"
#include<bits/stdc++.h>

using namespace std;


void searchHelper(Trie t , string document,int idx,unordered_map<string,bool>&map){
    Node* temp = t.root;
    for(int i=idx;i<document.size();i++){
        char ch = document[i];
        if(temp->m.count(ch) == 0){
            return ;
        }
        temp = temp->m[ch];
        if(temp->isTerminal){
            string out = document.substr(idx,i-idx+1);
            map[out] = true;
        }
    }
    return ;
}

void searchWords(string document,vector<string>words){
    Trie t;
    for(auto w : words)t.insert(w);
    unordered_map<string,bool>map;
    for(int i=0;i<document.size();i++){
        searchHelper(t,document,i,map);
    }
    for(string str : words){
        if(map[str] == true)cout<<"True ";
        else cout<<"False ";
    }
}


int main(){
    string document  ="little cute cat loves to code in c++, java & python";
    vector<string>words{"cute cat", "ttle", "cat","quick","big"};
    searchWords(document,words);
}