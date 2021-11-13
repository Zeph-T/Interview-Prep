class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        int longest = 0;
        int prefixSum = 0;
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(prefixSum == k)longest = i+1; // the longest possible till now
            if(prefix.find(prefixSum - k )!= prefix.end()){ // if the sum - k was already present,consider the index of the key
                longest = max(longest , i - prefix[prefixSum  - k]);
            }
            if(prefix.find(prefixSum) == prefix.end())prefix[prefixSum] = i; // this cannot be the longest possible, since we are increasing the value of i
        }
        return longest;
    }
};