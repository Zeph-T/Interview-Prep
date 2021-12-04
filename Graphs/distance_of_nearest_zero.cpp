class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
     
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){
                    dist[i][j] = 0;
                    q.push({i,j});
                    visited[i][j] = true;
                }
            }
        }
        int distance = 0;
        while(!q.empty()){
            distance++;
            int len = q.size();
            for(int i=0;i<len;i++){
                auto node = q.front();
                int x = node.first;
                int y = node.second;
                q.pop();
                for(int k=0;k<4;k++){
                    int newX = dx[k] + x;
                    int newY = dy[k] + y;
                    if(newX>=0 and newX < rows and newY >= 0 and newY < cols and !visited[newX][newY]){
                        dist[newX][newY] = min(dist[newX][newY],distance);
                        visited[newX][newY] = true;
                        q.push({newX,newY});
                    }
                }
                
            }

        }
        return dist;
        
        
    }
};