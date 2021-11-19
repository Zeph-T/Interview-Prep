class Solution {
public:
    int dx[4] = {0,0,-1,1};
    int dy[4] = {-1,1,0,0}; 
    
    void dfs(int x,int y,vector<vector<int>>& grid , vector<vector<bool>>&visited,int color){
        visited[x][y] = true;
        grid[x][y] = color;
        int m = grid.size();
        int n = grid[0].size();
        for(int k=0;k<4;k++){
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if(nx >=0 and nx < m and ny>=0 and ny < n and !visited[nx][ny] and grid[nx][ny] == 1){
                dfs(nx,ny,grid,visited,color);
            }
        }    
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)return -1;
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        int count  = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    dfs(i,j,grid,visited,count);
                    count++;
                }
            }
        }
        vector<pair<int,int>>first;
        vector<pair<int,int>>second;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<grid[i][j]<<" ";
                if(grid[i][j] == 1){
                    first.push_back({i,j});
                }else if(grid[i][j] == 2){
                    second.push_back({i,j});
                }
            }
            cout<<endl;
        }
        
        int ans = INT_MAX;
        for(auto x: first){
            for(auto y : second){
                ans = min(ans , abs(x.first - y.first) + abs(x.second - y.second ) - 1);
            }
        }
        
        return ans;
        
    }
};