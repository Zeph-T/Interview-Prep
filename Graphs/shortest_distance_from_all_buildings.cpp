class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int m = grid.size();
        int buildings = 0;
        if(m == 0)return 0;
        int n = grid[0].size();
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        vector<vector<int>>dist(m,vector<int>(n,0));    
        int reachTimes = 0;
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    buildings++;
                    q.push({i,j});
                    int distance = 0;
                    while(!q.empty()){
                        int len = q.size();
                        distance++;
                        for(int p=0;p<len;p++){
                            int x = q.front().first;
                            int y = q.front().second;
                            q.pop();
                            for(int k=0;k<4;k++){
                                int nx = x + dx[k];
                                int ny = y + dy[k];
                                if(nx >= 0 and nx < m and ny>=0 and ny < n and grid[nx][ny] == reachTimes){
                                    grid[nx][ny]--;
                                    dist[nx][ny] += distance;
                                    q.push({nx,ny});
                                }
                            }
                        }
                    }
                    reachTimes--;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(abs(grid[i][j]) == buildings and grid[i][j] < 0){
                    ans = min(ans , dist[i][j]);
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};