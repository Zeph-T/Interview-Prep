class Solution {
public:    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>g[n];
        vector<int>indegree(n,0);
        for(auto edge : edges){
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){ // only consider the leaf nodes
            if(indegree[i] == 1 or indegree[i] == 0)q.push(i);
        }
        vector<bool>visited(n,false);
        int count = 0;
        while(!q.empty()){
            if(count == n-1 or count == n-2)break;
            int len = q.size();
            for(int i=0;i<len;i++){ // move up the leaf nodes till we reach the centroid
                count++;
                int node = q.front();
                q.pop();
                visited[node] = true;
                for(int nbr : g[node]){
                    if(visited[nbr])continue;
                    indegree[nbr]--;
                    if(indegree[nbr] == 1)q.push(nbr);
                } 
            }
        }
        vector<int>ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
        
    }
};