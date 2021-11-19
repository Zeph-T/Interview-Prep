class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len  =1;
        int n = nums.size();
        int current = 1;
        for(int i=1;i<n;i++){
            if(nums[i] - nums[i-1] > 0){
                current++;
            }else{
                current = 1;
            }
            len = max(len  , current);
        }
        return len;
    }
};