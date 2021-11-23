class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0;
        int n = nums.size();
        int end = nums.size() - 1;
        while(start < end){
            int mid  = start + (end - start)/2;
            if(mid>0 and mid<n-1 and nums[mid] != nums[mid+1] and nums[mid-1] != nums[mid])return nums[mid];
            if(mid<n-1 and nums[mid] == nums[mid+1]){ // we check if the mid and mid+1 element are the same
                int rightCount = end-mid + 1; // then we club them to the right and check the length, 
                if(rightCount%2==0)end = mid-1; // if the length of the right segment is even, means that the right segment has one element which is not repeting
                else start = mid; // else the left segment has one element which is not repeating
                
            }else if(mid>0 and nums[mid] == nums[mid-1]){
                int leftCount = mid - start + 1; // vice versa
                if(leftCount%2==0)start = mid+1;
                else end = mid;
            }
        }
        return nums[start]; // return the start pointer
    }
};