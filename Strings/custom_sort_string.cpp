class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        for(char ch : s)mp[ch]++;
        string res="";
        for(char ch : order){
            if(mp.find(ch) != mp.end()){
                for(int i=0;i<mp[ch];i++)res+=ch;
                mp[ch] = 0;
            }
        }
        
        for(auto x : mp){
            if(x.second > 0){
                for(int i=0;i<x.second;i++)res+=x.first;
            }
        }
        
        return res;
        
    } 
};