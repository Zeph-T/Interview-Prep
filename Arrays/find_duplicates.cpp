class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int index = abs(nums[i]);
            if(nums[index - 1] < 0){
                ans.push_back(index);
            }
            nums[abs(index) - 1] = nums[abs(index) - 1] * -1;
            
        }   

        return ans;
    }
};