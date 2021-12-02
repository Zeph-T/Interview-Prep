class Solution {
public:
    long long numberOfSubstrings(string s) {
        unordered_map<char,long long int>dict;
        for(char ch  : s)dict[ch]++;
        long long int ans = 0;
        for(auto x : dict){
            ans += (x.second * (x.second + 1))/2;
        }
        return ans;
    }
};