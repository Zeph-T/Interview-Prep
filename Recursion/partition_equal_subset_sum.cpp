class Solution {
public:
    bool recur(vector<int>nums,int pos,vector<vector<int>>&dp , int target){
        
        if(target == 0)return true;
        if(pos == nums.size() or target < 0)return false;
        if(dp[pos][target] != -1)return dp[pos][target];
        
        
        return dp[pos][target] = recur(nums,pos+1,dp,target - nums[pos])  || recur(nums,pos+1,dp,target);
        
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        int n = nums.size();
        if(sum % 2 != 0)return false;
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return recur(nums,0, dp, sum/2);
        
    }
};