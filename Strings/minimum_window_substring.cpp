class Solution {
public:
    string minWindow(string s, string t) {
        int count[128];
        memset(count,0,sizeof(count));
        for(char ch : t)count[ch]++;
        int n = s.size();
        string ans = "";
        int not_included_char = t.size();
        int i=0;
        int max_len = INT_MAX;
        for(int j=0;j<n;j++){
            char ch = s[j];
            if(count[ch] > 0)not_included_char--;
            count[ch]--;
            while(not_included_char == 0){
                if(max_len > (j - i + 1)){
                    max_len = j - i + 1;
                    ans = s.substr(i,max_len);
                }
                count[s[i]]++;
                if(count[s[i]] > 0)not_included_char++;
                i++;
            }
        }
        return ans;
    }
};