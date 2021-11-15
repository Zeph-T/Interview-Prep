class Solution {
public:
    
    void dfs(int edge,vector<bool>&visited,vector<int>g[]){
        visited[edge]  = true;
        for(int node : g[edge]){
            if(!visited[node])
                dfs(node,visited,g);
        }
    }
    
    
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        int ans = 0;
        
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,g);
                ans++;
            }
        }
        return ans;
        
    }
};