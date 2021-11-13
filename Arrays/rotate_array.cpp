class Solution {
public:
    
    void swapSegment(vector<int>&nums,int i,int j){
        while(i < j){
            swap(nums[i++],nums[j--]);
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n ;
        swapSegment(nums,0,n-k-1); // reverse the first segment A,so it will become A`
        swapSegment(nums,n-k,n-1); // reverse the second segment B, so it will become B`
        swapSegment(nums,0,n-1);  // when combined => (A' + B')` = B + A
    }
};