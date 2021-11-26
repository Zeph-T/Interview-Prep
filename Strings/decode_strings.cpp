/*
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for(int i=2;i<=n;i++){
            int oneDigit = s[i-1] - '0';
            int TwoDigits = stoi(s.substr(i-2,2));
            if(oneDigit >= 1)dp[i] += dp[i-1];
            if(TwoDigits >= 10 and TwoDigits <=26 )dp[i] += dp[i-2];
        }
        return dp[n];
        
    }
};


/*
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int lastSecond = 1;
        int lastFirst = s[0] == '0' ? 0 : 1;
        
        
        for(int i=2;i<=n;i++){
            int current = 0;
            int oneDigit = s[i-1] - '0';
            int TwoDigits = stoi(s.substr(i-2,2));
            
            if(oneDigit >= 1){
                current = lastFirst;
            }
            if(TwoDigits >= 10 and TwoDigits <=26 ){
                current += lastSecond;
            }
            lastSecond = lastFirst;
            lastFirst = current;
        }
        return lastFirst;
        
    }
};