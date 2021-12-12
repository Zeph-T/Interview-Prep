

int solve(vector<int>& nums, int k) {
    int left = 0;
    int n = nums.size();
    int right = n;
    while(left < right){
        int mid = (left + right)/2;
        int nums_missing = nums[mid] - nums[0] - mid; // missing numbers till mid
        if(nums_missing <= k){
            left = mid+1;
        }else{
            right = mid;
        }
    }
    // left contains the position where it is just greater than k missing numbers
    // to get the kth missing number we substract the numbers missing till left and will add the k 
    return nums[left - 1] + k - (nums[left - 1] - nums[0] - left);
}