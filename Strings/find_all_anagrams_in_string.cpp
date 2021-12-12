class Solution {
public:
    bool check(int map[26],int window[26]){
        for(int i=0;i<26;i++)if(map[i] != window[i])return false;
        return true;
    }
    
    vector<int> findAnagrams(string s, string p) {
        int map[26];
        int window[26];
        memset(map,0,sizeof(map));
        memset(window,0,sizeof(window));
        int i=0;
        int j=0;
        int n = p.size();
        int n1 = s.size();
        vector<int>ans;
        for(char ch: p)map[ch-'a']++;
        while(j<n1){
            char ch = s[j];
            window[ch-'a']++;
            if(j - i + 1 == n){
                if(check(map,window))ans.push_back(i);
                window[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};