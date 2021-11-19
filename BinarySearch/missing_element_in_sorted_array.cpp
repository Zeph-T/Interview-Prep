class Solution {
public:
    int missingRange(vector<int>nums,int idx){
        return nums[idx] - idx - nums[0];
    }
    
    
    int missingElement(vector<int>& nums, int k) {
        if(k > missingRange(nums,nums.size()- 1)){
            return nums[nums.size() - 1] + k - missingRange(nums,nums.size() - 1);
        }
        int start = 0;
        int end = nums.size() - 1;
        while(start < end){
            int mid = start + (end - start)/2;
            
            if(missingRange(nums,mid) < k)start = mid + 1;
            else end = mid;
        }
        return nums[start - 1] + k - missingRange(nums,start-1); 
    }
};

/*
start pointer will have missing element equal to or greater than k,so we consider the element before the start pointer, and we add the count of elements which are missing from
till the start -1 pointer.
*/