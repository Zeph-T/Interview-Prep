class Solution {
public:
    int dx[4] =  {0,0,-1,1};
    int dy[4] = {-1,1,0,0};
    
    vector<vector<bool>> bfs(vector<vector<int>>heights,queue<pair<int,int>>q){
        int rows = heights.size();
        int cols = heights[0].size();
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(visited[x][y])continue;
            visited[x][y] = true;
            for(int k=0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx >= 0 and nx < rows and ny >= 0 and ny<cols and !visited[nx][ny] and heights[nx][ny] >= heights[x][y]){ // a node can only be reachable to ocean if the 
                                                                                                                            //height of that node is greater than or 
                                                                                                                            // equal to the height of the current node.

                    q.push({nx,ny});
                }
            }
        }
        
        return visited;
    }
    
    
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        if(rows == 0)return {{}};
        int cols = heights[0].size();
        queue<pair<int,int>> pq;
        queue<pair<int,int>>aq;
        for(int i=0;i<rows;i++){
            pq.push({i,0});
            aq.push({i,cols-1});
        }
        for(int i=0;i<cols;i++){
            pq.push({0,i});
            aq.push({rows-1,i});
        }
        
        vector<vector<bool>>reachableFromPacific = bfs(heights,pq); // mark te nodes reachable from pacific
        vector<vector<bool>>reachableFromAtlantic = bfs(heights,aq); // mark the ndoes reachable from atlanti
        
        vector<vector<int>>ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(reachableFromPacific[i][j]== true and reachableFromAtlantic[i][j] == true){ // take the intersection
                    ans.push_back({i,j});
                }
            }
        }
        
        return ans;
        
    }
};