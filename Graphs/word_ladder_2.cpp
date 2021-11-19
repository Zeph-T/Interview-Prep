class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>visited;
        queue<vector<string>>q;
        q.push({beginWord});
        unordered_set<string>words(wordList.begin(),wordList.end());
        vector<vector<string>>ans;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                auto curr_vector = q.front();
                q.pop();
                string last_updated = curr_vector.back();
                for(int i=0;i<last_updated.size();i++){
                    string temp = last_updated;
                    for(char ch = 'a';ch <= 'z';ch++){
                        temp[i] = ch;
                        if(words.count(temp) > 0){
                            visited.insert(temp);
                            auto new_vector = curr_vector;
                            new_vector.push_back(temp);
                            if(temp == endWord){
                                ans.push_back(new_vector);
                            }else{
                                q.push(new_vector);
                            }
                        }
                    }
                }    
            }
            for(string st : visited){
                words.erase(st);
            }
        }
        return ans;
    }
};