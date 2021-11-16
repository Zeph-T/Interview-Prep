class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    int dfs(vector<vector<int>>&matrix,int i,int j,vector<vector<int>>&cache){
        int m = matrix.size();
        int n = matrix[0].size();
        if(cache[i][j] != 0)return cache[i][j]; // if the coordinate is already calculated, there is no need to calculate again,
        for(int k=0;k<4;k++){ // we check through all the paths
            int x = i  + dx[k];
            int y = j + dy[k];
            if(x >=0 and x<m and y>=0 and y<n and matrix[x][y] > matrix[i][j]) 
                cache[i][j] = max(cache[i][j] , dfs(matrix,x,y,cache)); 
        }
        return ++cache[i][j]; // this will add the longest path  + the own len i.e 1
    } 
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0)return 0;
        int n = matrix[0].size();
        vector<vector<int>>cache(m,vector<int>(n,0));
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                ans = max(ans, dfs(matrix,i,j,cache));
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)cout<<cache[i][j]<<" ";
            cout<<endl;
        }
        return ans;
    }
};