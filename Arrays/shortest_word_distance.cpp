class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int index1 = INT_MIN;
        int index2 = INT_MAX;
        int n = words.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(words[i] == word1)index1 = i;
            if(words[i] == word2)index2 = i;
            if(index1 != INT_MIN and index2 != INT_MAX)
                ans = min(ans, abs(index1 - index2));
        }
        
        return ans;
    }
};