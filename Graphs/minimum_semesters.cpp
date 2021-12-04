class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<int>indegree(n+1,0),g[n+1];
        for(auto rel : relations){
            g[rel[0]].push_back(rel[1]);
            indegree[rel[1]]++;
        }
        
        queue<int>q;
        for(int i=1;i<=n;i++){
            if(indegree[i] == 0)q.push(i);
        }
        if(q.size() == 0 or q.size() == n)return -1;
        int count = 0;
        vector<bool>visited(n+1,false);
        while(!q.empty()){
            int len = q.size();
            for(int i = 0;i<len;i++){
                int node = q.front();
                q.pop();
                if(visited[node])continue;
                visited[node] = true;
                for(int nbr : g[node]){
                    if(!visited[nbr]){
                        indegree[nbr]--;
                        if(indegree[nbr] == 0)q.push(nbr);
                    }   
                }
            }
            count++;
        }
        for(int i=1;i<=n;i++)if(visited[i] == false)return -1;
        return count;
        
    }
};