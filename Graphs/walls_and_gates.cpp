class Solution {
public:
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    void wallsAndGates(vector<vector<int>>& rooms) {
        queue<pair<int,int>>q;
        int rows = rooms.size();
        int cols = rooms[0].size();
        
        for(int i=0; i< rows; i++){
            for(int j=0;j<cols;j++){
                if(rooms[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        
        int distance = 0;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int x = q.front().first;
                int y = q.front().second;
                visited[x][y] = true;
                
                q.pop();
                rooms[x][y] = min(distance,rooms[x][y]);

                for(int k=0;k<4;k++){
                    int newX = x + dx[k];
                    int newY = y + dy[k];
                    if(newX>=0 and newX<rows  and newY >= 0 and newY < cols and rooms[newX][newY] == INT_MAX and !visited[newX][newY] ){
                        q.push({newX,newY});
                    }
                }
            }
            distance++;
        }
        
    }
};