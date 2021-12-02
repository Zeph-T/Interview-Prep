class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i % 2 == 0){ // for the even index, the array value shuold be less than the next element, else we swap with the next value
                if(i < n-1 and nums[i] > nums[i+1])swap(nums[i] , nums[i+1]);
            }else{ // for the odd index, the array value should be greater than the next element, else we swap with the next value
                if(i < n-1 and nums[i] < nums[i+1])swap(nums[i] , nums[i+1]);
            }
        }
        
    }
};