class Solution
{
    public:
    bool ans = false;
    
	//Function to detect cycle in a directed graph.
	void dfs(int node , vector<int>adj[],vector<bool>&seen , vector<bool>&visited){
	    visited[node] = true;
	    seen[node] = true;
	    for(auto nbr : adj[node]){
	        if(!visited[nbr]){
	            dfs(nbr , adj , seen , visited);
	        }else{
	            if(seen[nbr]) ans = true;
	        }
	    }
	    seen[node] = false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	    vector<bool>seen(V,false);
	    vector<bool>visited(V,false);
	    for(int i=0;i<V;i++){
	        if(!visited[i])
	            dfs(i , adj , seen , visited);
	    }
        return ans;	    
	   	// code here
	}
};