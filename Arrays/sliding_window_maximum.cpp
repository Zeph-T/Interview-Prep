class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        list<int>l;
        int windowStart = 0;
        int n = nums.size();
        vector<int>ans;
        for(int windowEnd = 0;windowEnd < n;windowEnd++){
            int top = nums[windowEnd];
            while(l.size() and l.back() < nums[windowEnd])l.pop_back(); // at each iteration we keep the list in ascending order
            l.push_back(nums[windowEnd]);
            
            if(windowEnd - windowStart + 1 == k){
                ans.push_back(l.front());
                if(nums[windowStart] == l.front())l.pop_front(); // we remove the front element if the element at startWindow is the same as the front element
                windowStart++;
            } 
        }
        return ans;
    }
};