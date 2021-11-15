class Solution {
public:
    vector<int>prefix;
    int len = 0;
    Solution(vector<int>& w) {
        len = w.size();
        prefix.push_back(w[0]);
        for(int i=1;i<len;i++)
            prefix.push_back(w[i] + prefix[i-1]);
        
    }
    
    int pickIndex() {
        int target = rand() % prefix.back();
        return upper_bound(prefix.begin(),prefix.end() , target) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */