class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = n-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(mid > 0 and mid < n-1 and nums[mid-1] > nums[mid] and nums[mid] < nums[mid+1])return nums[mid];
            
            if(nums[mid] > nums[end]){
                start = mid+1;
            }else{
                end = mid-1;
            }
            
        }
        return nums[start];
    }
};