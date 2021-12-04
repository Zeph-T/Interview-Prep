

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int sum  =0;
        int n = nums.size();
        int len = INT_MAX;
        for(int end = 0;end < n ; end++){
            sum += nums[end];
            while(sum >= target){
                len = min(len , end - start + 1);
                sum -= nums[start++];
            }
        }
        return len == INT_MAX ? 0 : len;
    }
};