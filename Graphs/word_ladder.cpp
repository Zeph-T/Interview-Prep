class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string>words(wordList.begin(),wordList.end());
        if(words.find(endWord) == words.end())return 0;
        int dist = 1; // starting from the begin word
        queue<string>q;
        q.push(beginWord);
        while(!q.empty()){
            int size = q.size();
            for(int h=0;h<size;h++){
                string top = q.front();
                q.pop();
                for(int i=0;i<top.size();i++){ // try changing each character and check if the new string is present inside our set
                    char c = top[i];
                    for(char ch= 'a';ch <= 'z';ch++){ // change the letter by taking all possible values
                        top[i] = ch;
                        if(words.find(top) != words.end()){
                            if(top == endWord)return dist+1; 
                            q.push(top);
                            words.erase(top);
                        }
                    }
                    top[i] = c;
                }
            }
            dist++;
        }
        return 0;
    }
};