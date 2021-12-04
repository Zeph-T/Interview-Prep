class Solution {
public:
    vector<bool>visited;
    
    
    void dfs(int node , vector<int>g[]){
        visited[node] = true;
        for(int nbr : g[node]){
            if(!visited[nbr])dfs(nbr,g);
        }
        return ;
    }
    
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        int num_connections = connections.size();
        if(num_connections < n - 1)return -1;
        int connected_components = 0;
        visited.resize(n,false);
        vector<int>g[n];
        for(auto connect : connections){
            g[connect[0]].push_back(connect[1]);
            g[connect[1]].push_back(connect[0]);
        }
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,g);
                connected_components++;
            }
        }
        return connected_components - 1;
    }
};