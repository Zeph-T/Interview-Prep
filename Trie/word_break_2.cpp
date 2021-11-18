class Solution {
    
    struct TrieNode {
        TrieNode* child[26];
        bool end;
        TrieNode(){
            for(int i=0;i<26;i++)child[i] = NULL;
            end = false;
        }
    };
    TrieNode* root;
    vector<string>ans;
    
    void buildTrie(vector<string>&wordDict){ // build the trie
        TrieNode* itr;
        for(string &word : wordDict){
            itr = root;
            for(char&c:word){
                if(itr->child[c-'a']==NULL){
                    itr->child[c-'a'] = new TrieNode();
                }
                itr = itr->child[c-'a'];
            }
            itr->end = true;
        }
    }
    
    void solve(string s,string local,int ind,int n){ // build the local string with all the possible strings inside the trie
        if(ind==s.size())ans.push_back(local);
        else{
            TrieNode* itr = root;
            for(int i=ind;i<n;i++){
                if(itr->child[s[i]-'a']==NULL)return;
                itr = itr->child[s[i]-'a'];
                if(itr->end){ // if any substring is found! , add the string to the local and recur for the res of the substring
                    string temp = s.substr(ind,i-ind+1) + " ";
                    solve(s,local+temp,i+1,n);
                }
            }
        }
    }
    
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        root = new TrieNode();
        buildTrie(wordDict);
        solve(s,"",0,s.size());
        for(string &str : ans){
            str.pop_back();
        }
        return ans;
    }
};