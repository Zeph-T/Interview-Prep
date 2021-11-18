class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int distance = 0;
        for(int bit=0;bit<32;bit++){
            int zeros  = 0;
            int ones = 0;
            for(int num : nums){
                if((num >> bit)&1)ones++;
                else zeros++;
            }
            distance += (ones * zeros);
        }
        return distance;
    }
};