class WordDistance {
public:
    unordered_map<string,vector<int>>hash;
    WordDistance(vector<string>& wordsDict) {
        for(int i=0;i < wordsDict.size();i++){
            hash[wordsDict[i]].push_back(i); 
        }
    }
    
    int shortest(string word1, string word2) {
        if(hash.count(word1) > 0 and hash.count(word2)>0){
            int p1 = 0 , p2 = 0;
            vector<int>w1 = hash[word1];
            vector<int>w2 = hash[word2];
            int diff = INT_MAX;
            while(p1 < w1.size() and p2 < w2.size()){
                diff = min(diff ,abs(w1[p1] - w2[p2]));
                if(w1[p1] < w2[p2])p1++;
                else p2++;
            }
            return diff;
        }
        return -1;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */