class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        int count = 0;
        vector<int>g[n];
        vector<int>indegree(n,0);
        queue<int>q;
        vector<bool>visited(n,false);
        for(auto graph : pre){
            g[graph[0]].push_back(graph[1]);
            indegree[graph[1]]++;
        }
        
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)q.push(i);
        }
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            if(visited[node])continue;
            count++;
            visited[node] = true;
            for(int nbr : g[node]){
                if(!visited[nbr]){
                    indegree[nbr]--;
                }
                if(indegree[nbr] == 0)q.push(nbr);
            }
        }
        return count == n;
        
    }
};