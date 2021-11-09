#include<iostream>
#include"trie.h"


using namespace std;





int main(){
    Trie tree;
    string words[4] = {"hello","world","where","news"};
    for(string str: words){
        tree.insert(str);
    }
    string find="hello";
    if(tree.search(find))cout<<"true";
    else cout<<"false";
    return 0;
}