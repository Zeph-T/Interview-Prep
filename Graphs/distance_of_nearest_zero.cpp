class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
     
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        queue<pair<int,int>>q;
        vector<vector<int>>dist(rows,vector<int>(cols,INT_MAX));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j] == 0){ // no need to travel the matrix, since the distance to reach zero is zero
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty()){
            auto node = q.front();// from each zero node, we will do a BFS and since the call from one cell to another differ by atmost 1
                                    // we consider te minimum of the new coordinate
            int x = node.first;
            int y = node.second;
            q.pop();
            for(int k=0;k<4;k++){
                int newX = dx[k] + x;
                int newY = dy[k] + y;
                if(newX>=0 and newX < rows and newY >= 0 and newY < cols){ 
                    if(dist[newX][newY] > dist[x][y] + 1){
                        dist[newX][newY] = dist[x][y] + 1;
                        q.push({newX,newY});
                    }
                }
            }
        }
        return dist;
        
        
    }
};