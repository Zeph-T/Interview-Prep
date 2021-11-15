class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    
    void dfs(int x,int y,vector<vector<char>>&grid){ // flood fill
        int n = grid.size();
        int m = grid[0].size();
        grid[x][y] = '0';
        for(int k=0;k<4;k++){
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if(nx >= 0 and nx < n and ny >=0 and ny<m and grid[nx][ny] == '1'){
                dfs(nx,ny,grid);
            }
        }
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0)return 0;
        int m = grid[0].size();
        int ans =0 ;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};