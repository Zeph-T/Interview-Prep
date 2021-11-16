/*
The Appraoch is simple , we construct the prefix sum, and since we are asked contiguous subarray, ie. sum(i,j)_ = (prefix[j] - prefix[i-1]) %k  == 0
prefix[i]%k == prefix[j]%k;
value when divided by k -> [0,5]

23 2 4 6 7
5 1 5 5 0
k = 6
(23 + 2)%k = 1
(5 + 2)%k = 1

*/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        map[0] = -1;
        int sum = 0;
        int n= nums.size();
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(k != 0) sum = sum%k;
            if(map.find(sum) != map.end()){ 
                if(i - map[sum] >= 2)return true;
            }else
                map[sum] = i;
        }
        return false;
    }
};