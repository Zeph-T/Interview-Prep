class Solution {
public:
    int expand(string s,int left,int right){
        int l = left;
        int r = right;
        while(l>=0 and r < s.size()  and s[r] == s[l]){
            l--;
            r++;
        }
        return r - l - 1;
    }
    
    string longestPalindrome(string s) {
        if(s.size() == 0)return "";
        int l = 0;
        int r = 0;
        int n = s.size();
        for(int i=0;i<s.size();i++){
            int l1 = expand(s,i,i+1);
            int l2 = expand(s,i,i);
            int len_current = max(l1,l2);
            if(len_current > (r - l + 1))
            {
                l = i - (len_current - 1)/2;
                r = i + len_current /2;
            }
        }
        return s.substr(l,r-l+1);
    }
};