class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>ans;
        vector<int>g[n];
        int count = 0;
        vector<int>indegree(n,0);
        queue<int>q;
        vector<bool>visited(n,false);
        for(auto graph : pre){
            g[graph[1]].push_back(graph[0]);
            indegree[graph[0]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node])continue;
            ans.push_back(node);
            count++;
            visited[node] = true;
            for(int nbr : g[node]){
                if(!visited[nbr]){
                    indegree[nbr]--;
                }
                if(indegree[nbr] == 0)q.push(nbr);
            }
        }
        if(count == n)
            return ans;
        return {};
    }
};