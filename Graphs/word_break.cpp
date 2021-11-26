class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>words(wordDict.begin(),wordDict.end());
        queue<pair<int,string>>q;
        q.push({0,""});
        vector<bool>visited(s.size(),false);
        while(!q.empty()){
            int index = q.front().first;
            string curr = q.front().second;
            if(index == s.size())return true;
            q.pop();
            if(visited[index] == true)continue;
            visited[index] = true;
            for(string word : words){
                int string_len = word.size();
                if(visited[index+string_len] == false and s.substr(index,string_len) == word){
                    q.push({index+string_len , curr + s.substr(index,string_len)});
                }
            }
        }
        return false;
    }
};