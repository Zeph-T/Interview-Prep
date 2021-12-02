class Solution {
public:
    vector<bool>visited;
    
    void dfs(vector<int>g[],int node){
        visited[node] = true;
        for(int nbr : g[node]){
            if(visited[nbr] == false){
                dfs(g,nbr);
            }
        }
    }
    
    
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<int>g[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j and mat[i][j] == 1){
                    g[i].push_back(j);
                }
            }
        }
        visited.resize(n+1,false);
        int count = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(g,i);
                count++;
            }
        }
        return count;
        
        
    }
};