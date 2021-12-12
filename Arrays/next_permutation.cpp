class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1 or n == 0)return ;
        int i = n-2;
        while( i >=0 and nums[i] >= nums[i+1] )i--;
        if(i >= 0){
            int j = nums.size() - 1;
            while(nums[j] <= nums[i])j--;
            swap(nums[i],nums[j]);
        }
        reverse(nums,i+1,n-1);
    }
    
    void reverse(vector<int>&nums,int i,int j){
        while(i<j){
            swap(nums[i++],nums[j--]);
        }
    }
};