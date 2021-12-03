class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        int start = 0;
        int end = 0;
        int n = nums.size();
        for(int i,j=0;j<n;j++){
            i = j;
            while(j < n-1 and (int)(nums[j+1]) - (int)(nums[j]) == 1)j++;
            if(i == j)ans.push_back(to_string(nums[i]));
            else ans.push_back(to_string(nums[i]) + "->" + to_string(nums[j]));
        }
        return ans;
    }
};