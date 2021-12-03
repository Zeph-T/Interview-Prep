/*
Note that we can use the right shift operator as well, but as we know, we can atmost shift 32 bits or 64bits based
on the datatype, so instead of that, we can use the built array to get the 2^(left-right)


Time Complexity : O(N)
Space Complexity : O(N)
*/


class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size()-1,n=nums.size();
        int ans = 0;
        long mod = 1e9+7;
        vector<int>pow(n,1);
        for(int i=1;i<n;i++){
            pow[i] = (pow[i-1] * 2)%mod; 
        }
        while(left <= right){
            if(nums[left] + nums[right] > target){
                right--;
            }else{
                ans =(ans  + pow[right-left])%(mod);
                left++;
            }
        }
        return ans;
    }
};