class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff = INT_MAX;
        int sum;
        int ans = 0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int start = i+1;
            int end = n-1;
            while(start < end){
                int num = nums[start] + nums[end] + nums[i];
                if(abs(target - num ) < abs(diff)){
                    diff = target - num;
                    ans = num;
                }
                if(num < target)start++;
                else end--;
            }
        }
        return ans;
    }
};