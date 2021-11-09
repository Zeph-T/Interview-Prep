class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int dict[26];
        int n = order.size();
        for(int i=0;i<n;i++)dict[order[i] - 'a'] = i;
        n= words.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int size = min(words[i].size() , words[j].size());
                for(int k=0;k<size;k++){
                    if(dict[words[i][k] - 'a'] < dict[words[j][k] - 'a'])break;
                    else if(dict[words[i][k] - 'a'] > dict[words[j][k] - 'a'])return false;
                    else if(k == size - 1 and words[i].size() > words[j].size())return false;
                }
            }
        }
        return true;
    };
};