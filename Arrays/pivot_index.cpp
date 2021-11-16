class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end() , 0);
        int lsum  =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(lsum  == sum - nums[i] - lsum)return i; // getting the sum of all the elements - lsum gives rsum
            lsum += nums[i];
        }
        return -1;
    }
};