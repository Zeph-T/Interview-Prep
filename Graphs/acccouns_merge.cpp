class Solution {
public:
    unordered_map<string,vector<string>>adj;
    unordered_set<string>visited;
    
    
    
    void dfs(vector<string>&accounts,string email){
        visited.insert(email);
        accounts.push_back(email);
        for(string nbr : adj[email]){
            if(visited.find(nbr) == visited.end()){
                dfs(accounts,nbr);
            }
        }
    }
    
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        for(auto account : accounts){
            int account_size = account.size();
            string first_account = account[1];
            for(int i=2;i<account.size();i++){
                string email = account[i];
                adj[email].push_back(first_account);
                adj[first_account].push_back(email);
            }    
        }
        
        vector<vector<string>>merged;
        
        for(auto account : accounts){
            vector<string>merge_account;
            string account_name = account[0];
            string first_email = account[1];
            if(visited.find(first_email)  == visited.end()){
                merge_account.push_back(account_name);
                dfs(merge_account,first_email);
                sort(merge_account.begin()+1,merge_account.end());
                merged.push_back(merge_account);
            }
        }
        
        
        return merged;
    }
};