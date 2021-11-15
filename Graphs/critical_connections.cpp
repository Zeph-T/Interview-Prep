
/*
Time Complexity ; O(V + E)
Space Complexity : O(V + E) = O(E)
*/

class Solution {
public:
    int id = 0;
    void dfs(vector<int>g[] , vector<int>&ids,vector<int>&lows,vector<bool>&visited,vector<vector<int>>&art,int at,int parent ){
        visited[at] = true;
        ids[at] = lows[at] =  ++id;
        for(int to : g[at]){
            if(to == parent)continue;
            if(!visited[to]){
                dfs(g,ids,lows,visited,art,to,at);
                lows[at] = min(lows[to] , lows[at]);
                if(ids[at] < lows[to]){
                    art.push_back({to,at});
                }
            }else{
                lows[at] = min(lows[at] , ids[to]);
            }
        }
    }
    
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>ids(n);
        vector<int>lows(n);
        vector<bool>visited(n,false);
        vector<vector<int>>art;
        vector<int>g[n];
        for(auto edge : connections){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        } 
        
        dfs(g,ids,lows,visited,art,0,-1);
        return art;
    }
};