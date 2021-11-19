class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        
        vector<pair<int,int>>g[n+1];
        
        for(auto pipe : pipes){
            g[pipe[0]].push_back({pipe[1] , pipe[2]});
            g[pipe[1]].push_back({pipe[0] , pipe[2]});
        }
        
        for(int i=1;i<=n;i++){ // consider digging a well as an virtual node where all nodes are connected to it
            g[i].push_back({0,wells[i-1]});
            g[0].push_back({i,wells[i-1]});
        }
        
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,0});
        
        int ans = 0;
        
        vector<bool>visited(n+1,false);
        
        
        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            if(visited[top.second] == true)continue;
            ans += top.first;
            visited[top.second] = true;
            
            for(auto nbr : g[top.second]){
                int nbrNode = nbr.first;
                int nbrWt = nbr.second;
                if(!visited[nbrNode]){
                    pq.push({nbrWt,nbrNode});
                }
            }
        }
        return ans;
        
    }
};