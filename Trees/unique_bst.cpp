class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[1] = 1;
        dp[0] = 1;
        for(int i=2;i<=n;i++){ // trees with i number of nodes
            for(int j=1;j<=i;j++){ // consider root to be the jth node 
                dp[i] +=  dp[j - 1] * dp[i - j];
            }
        }
        return dp[n];
        
        
    }
};