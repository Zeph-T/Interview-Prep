class Solution {
public:
    int expandAroundCenter(string s,int n1,int n2){
        int n = s.size();
        int count = 0;
        while(n1 >= 0 and n2 < n and s[n1] == s[n2]){
            count++;
            n1--;
            n2++;
        }
        return count;
    }
    
    
    int countSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += expandAroundCenter(s,i,i);
            ans += expandAroundCenter(s,i,i+1);
        }
        return ans;
    }
};