/*
Using Recursion and memoization
Time Complexity : O(N + L^2 * N)
Space Complxity : O(N)
*/


class Solution {
public:
    int dp[1001];
    
    
    static bool comp(string word1,string word2){
        return word1.size() < word2.size();
    }
    
    bool valid(string word1,string word2){
        int len1 = word1.size();
        int len2 = word2.size();
        if(len1 == len2)return false;
        if(len2 - len1 > 1)return false;
        int p1 = 0;
        int p2 = 0;
        bool skipped = false;
        while(p1 < len1 and p2 < len2){
            if(word1[p1] != word2[p2]){
                if(skipped)return false;
                p2++;
                skipped = true;
            }else{
                p1++;
                p2++;
            }
        }
        
        if(!skipped or (p1 == len1 and p2 == len2))return true;
        else return false;
    }
    
    
    
    int dfs(int idx,vector<string>words){
        if(idx == words.size())return 0;
        if(dp[idx] != -1)return dp[idx];
        int n = words.size();
        int ans = 1;
        for(int next = idx+1;next < n ; next++){
            if(valid(words[idx] , words[next])){
                ans = max(ans , 1 + dfs(next , words));
            }
        }
        return dp[idx] = ans;
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        memset(dp,-1,sizeof(dp));
        sort(words.begin(),words.end(),comp);
        int ans = -1;
        
        for(int idx = 0 ; idx < words.size();idx++){
            ans = max(ans ,dfs(idx,words));
        }
        return ans;
    }
};


/*

Using BFS
For Each word, we see the index, if the compute length of the longest string chain ending with words[index]

*/



class Solution {
public:
    vector<int>dp;
    unordered_map<string,int>map;
    
    void bfs(vector<string>&words,string word,int index){
        queue<pair<string,pair<int,int>>>q;
        q.push({word,{1,index}});
        int n = words.size();
        vector<bool>visited(n,false);
        
        while(!q.empty()){
            auto curr = q.front();q.pop();
            string curr_word = curr.first;
            int word_index = curr.second.second;
            int current_len = curr.second.first;
            
            if(visited[word_index])continue;
            visited[word_index] = true;
            dp[word_index] = max(dp[word_index] , current_len);
            
            for(int idx = 0 ; idx < curr_word.size() ; idx++){
                string new_word = curr_word.substr(0,idx) + curr_word.substr(idx+1);
                if(map.count(new_word)){
                    q.push({new_word,{current_len + 1 , map[new_word] }});
                }
            }   
        }
    }
    
    
    
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        dp.resize(n,-1);
        for(int i=0;i<n;i++)map[words[i]] = i;    
        
        for(int i=n-1;i>=0;i--){
            if(dp[i] != -1)continue;
            else bfs(words,words[i] , i);
        }
        
        return *max_element(dp.begin(),dp.end());
        
    }
};