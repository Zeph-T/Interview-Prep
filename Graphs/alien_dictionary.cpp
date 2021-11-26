class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char,vector<char>>g;
        unordered_map<char,int>indegree;
        
        for(string word : words){
            for(char ch : word)indegree[ch] = 0;
        }
        
        
        for(int i=0;i<words.size()-1;i++){
            string current = words[i];
            string next = words[i+1];
            
            int len = min(current.size() , next.size());
            
            for(int j=0;j<len;j++){
                char ch1 = current[j];
                char ch2 = next[j];
                if(ch1 != ch2){
                    if(find(g[ch1].begin() , g[ch1].end() , ch2) == g[ch1].end()){
                        g[ch1].push_back(ch2);
                        indegree[ch2]++; 
                    }
                    break;
                }
                 if(j == len-1  and words[i].size() > words[i+1].size())
                        return "";
            }
        }
        
        queue<char>q;
        string ans="";
        for(auto x:  indegree){
            if(x.second == 0)q.push(x.first);
        }
        int count = 0;
        while(!q.empty()){
            char top = q.front();
            q.pop();
            ans+=top;
            count++;
            for(char ch : g[top]){
                indegree[ch]--;
                if(indegree[ch] == 0){
                    q.push(ch);
                }
            }
        }
        
        if(count == indegree.size())return ans;
        return "";
    }
};