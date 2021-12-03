/*
Time Complexity : O(N^2)
Space Complexity : O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j] > nums[i] and dp[j] <= dp[i]){
                    dp[j] = dp[i]  +1;
                }
            } 
        }
        int max_length = 1;
        for(int i=0;i<n;i++){
            max_length = max(max_length , dp[i]);
        }
        return max_length;
    }
};



/*
Using Binary search for building the LIS
we insert a new element inside the LIS if we can insert it at the back
else we replace it with the lower bound of the number
Time Complexity : O(NLogN)
Space Complexity : O(N)
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>subs;
        for(int num  :nums){
            auto iterator = lower_bound(subs.begin(),subs.end() , num);
            if(iterator == subs.end())subs.push_back(num);
            else *iterator = num;
        }
        return subs.size();
    }
};