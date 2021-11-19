/*
Bucket Sort
TC O(N)
SC O(N)
*/


class Solution {
public:
    
    string frequencySort(string s) {
        string res="";
        map<char,int>mp;
        for(char ch  : s)mp[ch]++;
        int n = s.size();
        vector<char>buckets[n+1];
        for(auto x : mp){
            buckets[x.second].push_back(x.first);
        }
        
        for(int i=n;i>=0;i--){
            if(buckets[i].size() > 0){
                for(int j=0;j<buckets[i].size();j++){
                    for(int counter = 0;counter < i;counter++)res+=buckets[i][j];
                }
            }
        }
        return res;
        
    }
};