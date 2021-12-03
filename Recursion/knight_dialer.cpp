class Solution {
public:
    vector<vector<vector<int>>>dp;
    int rows = 4;
    int cols = 3;
    int directions[8][2] = {{1,2},{2,1},{-1,-2},{-2,-1},{-2,1},{-1,2},{2,-1},{1,-2}};
    
    int dfs(int x,int y,int n){
        if(x > 3 or x < 0 or y > 2 or y < 0 or (x == 3 and (y == 0 or y == 2)))return 0;
        if(n == 0)return 0;
        if(n == 1)return 1;
        if(dp[n][x][y] > 0)return dp[n][x][y];
        long ans = 0;
        int mod = 1e9+ 7;
        for(int i=0;i<8;i++){
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];
            ans += dfs(newX , newY , n-1);
        }
        return dp[n][x][y] = ans%mod;
    }
    
    int knightDialer(int n) {
        dp.resize(n+1,vector<vector<int>>(4,vector<int>(3,0)));
        long ans = 0;
        int mod = 1e9+7;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                ans += dfs(i,j,n);
                ans = ans%mod;
            }
        }
        return (int)ans;
    }
};