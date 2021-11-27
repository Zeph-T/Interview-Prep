class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 0)return 0;
        int max_so_far = nums[0];
        int min_so_far = nums[0];
        int result = max_so_far;
        int ans = 0;
        for(int i=1;i<n;i++){
            int temp = max_so_far;
            max_so_far = max(nums[i] , max(max_so_far * nums[i] , min_so_far * nums[i] ));
            min_so_far = min(nums[i ] , min(temp * nums[i] , min_so_far * nums[i]));
            result = max(result , max_so_far);
        }
        return result;
        
    }
};