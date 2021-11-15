class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    void flood_fill(int x,int y,int col,vector<vector<int>>&grid,vector<vector<bool>>&visited,vector<int>&colorCount){
        grid[x][y] = col;
        int n = grid.size();
        colorCount[col]++;
        int m = grid[0].size();
        visited[x][y] = true;
        for(int k=0;k<4;k++){
            int nx = dx[k] + x;
            int ny = dy[k] + y;
            if(nx >= 0 and nx < n and ny >=0 and ny < m and !visited[nx][ny] and grid[nx][ny] == 1){
                flood_fill(nx,ny,col,grid,visited,colorCount);
            }
        }
    }
    
    
    
    int largestIsland(vector<vector<int>>& grid) {
        vector<int>colorCount(1e5,0);
        int n = grid.size();
        if(n == 0)return 0;
        int m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool>(m,false));
        int islands = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    islands++;
                    flood_fill(i,j,islands,grid,visited,colorCount);
                }
            }
        }
        
        int largest = 0;
        
        
        for(int i=1;i<=islands;i++)
            largest = max(largest , colorCount[i]);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    set<int>st;
                    for(int k=0;k<4;k++){
                        int nx = dx[k] + i;
                        int ny = dy[k] + j;
                        if(nx >= 0 and nx < n and ny >=0 and ny < m and visited[nx][ny] and grid[nx][ny] > 0){
                            st.insert(grid[nx][ny]);
                        }
                    }
                    int count = 0;
                    for(int color : st){
                        count += colorCount[color];
                    }
                    largest = max(largest , count + 1);
                    
                }
            }
        }
        return largest;
    }
};