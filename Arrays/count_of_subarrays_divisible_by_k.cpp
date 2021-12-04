class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        int rem = 0;
        unordered_map<int,int>map;
        map[0] = 1;
        for(int num : nums){
            sum += num;
            rem = sum%k;
            
            if(rem < 0){
                rem += k;
            }
            count += map[rem];
            
            map[rem]++;
        }
        return count;
    }
};