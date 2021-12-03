class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=0;
        int j=nums.size()-1;
        int ans = -1;
        while(i < j){
            int sum  = nums[i] + nums[j];
            if(sum < k){
                ans = max(ans , sum);
                i++;
            }else{
                j--;
            }
        }
        return ans;
    }
};