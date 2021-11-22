class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int rows = arr.size();
        if(rows == 0)return 0;
        int cols = arr[0].size();
        vector<vector<int>>dp(rows,vector<int>(cols,0));
        
        if(arr[0][0] == 1)return 0;
        dp[0][0] = 1;
        for(int i=1;i<rows;i++){
            if(arr[i][0] == 1)dp[i][0] = 0;
            else dp[i][0] = dp[i-1][0];
        }
        
        for(int i=1;i<cols;i++){
            if(arr[0][i] == 1)dp[0][i] = 0;
            else dp[0][i] = dp[0][i-1];
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(arr[i][j] == 1)dp[i][j] = 0;
                else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[rows-1][cols-1];
    }
};