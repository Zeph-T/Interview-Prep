class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};