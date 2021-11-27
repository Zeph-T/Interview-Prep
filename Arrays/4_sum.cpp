class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        int n = nums.size();
        if(n <= 3)return ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int required = target - nums[i] - nums[j];
                int start = j+1;
                int end = n-1;
                while(start < end){
                    int sum = nums[start] + nums[end];
                    if(sum == required){
                        vector<int>temp(4,0);
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[start];
                        temp[3] = nums[end];
                        ans.push_back(temp);
                        while(start < end and nums[start] == temp[2])start++;
                        while(start < end and nums[end] == temp[3])end--;
                    }else if(sum > required){
                        end--;
                    }else{
                        start++;
                    }
                }
                while(j < n-1 and nums[j+1] == nums[j])j++; // handling duplicates
            }
            while(i < n - 1 and nums[i] == nums[i+1])i++; // handling duplicates
        }
        return ans;
    }
};