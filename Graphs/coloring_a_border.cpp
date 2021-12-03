class Solution {
public:
    
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    int rows = 0;
    int cols = 0;
    vector<vector<int>>grid;
    vector<vector<bool>>visited;
    vector<pair<int,int>>border;
    
    
    bool dfs(int row,int col,int colorRequired){
        if(row >= rows or col >= cols or col < 0 or row < 0 or grid[row][col] != colorRequired)return false;
        if(visited[row][col])return true;
        visited[row][col] = true;
        bool a = dfs(row + dx[0] , col + dy[0] , colorRequired);
        bool b = dfs(row + dx[1] , col + dy[1] , colorRequired);
        bool c = dfs(row + dx[2] , col + dy[2] , colorRequired);
        bool d = dfs(row + dx[3] , col + dy[3] , colorRequired);
        if((a and b and c and d) == 0)border.push_back({row,col});
        return true;
        
    }
    
    
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        this->grid = grid;
        rows = grid.size();
        cols = grid[0].size();
        visited.resize(rows,vector<bool>(cols,false));
        
        if(grid[row][col] != color)dfs(row,col,grid[row][col]);
        
        for(auto borderEle : border){
            grid[borderEle.first][borderEle.second] = color;
        }
        return grid;
    }
};