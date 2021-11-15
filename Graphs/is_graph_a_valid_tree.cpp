class Solution {
public:
    bool dfs(int src,int parent,vector<int>g[],vector<bool>&visited){
        visited[src] = true;
        for(auto nbr : g[src]){
            if(!visited[nbr]){
                bool found = dfs(nbr,src,g,visited);
                if(found)return true;
            }else if(nbr != parent)return true;
        }
        return false;
    }
    
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<bool>visited(n,false);
        vector<int>g[n];
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        
        
        
        bool cycleFound =  !dfs(0,-1,g,visited);
        for(bool x: visited){
            if(x == false)return false;
        }
        return cycleFound;
        
    }
};