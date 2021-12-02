class Solution {
public:
    
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        unordered_map<string,vector<string>>g;
        if(n1 != n2)return false;
        
        for(auto nodes : similarPairs){
            g[nodes[0]].push_back(nodes[1]);
            g[nodes[1]].push_back(nodes[0]);
        }
        
        for(int i=0;i<n1;i++){
            string s1 = sentence1[i];
            string s2 = sentence2[i];
            if(s1 == s2)continue;
            unordered_set<string>visited;
            queue<string>q;
            q.push(s1);
            visited.insert(s1);
            bool found = false;
            while(!q.empty()){
                string top = q.front();
                q.pop();
                if(top == s2){
                    found = true;
                    break;
                }
                for(string nbr : g[top]){
                    if(visited.count(nbr) == 0){
                        visited.insert(nbr);
                        q.push(nbr);
                    }
                }
            }
            
            if(!found)return false;           
        }
        
        
        return true;
        
        
        
        
    }
};