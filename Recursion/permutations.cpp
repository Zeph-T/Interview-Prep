class Solution {
public:
    vector<vector<int>>ans;
    
    void permutations(int pos,vector<int>&nums){
        if(pos == nums.size()){
            ans.push_back(nums);
            return ;
        }
        int n = nums.size();
        for(int i=pos;i<n;i++){
            swap(nums[i] , nums[pos]);
            permutations(pos+1,nums);
            swap(nums[i] , nums[pos]);
        }
        return ;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permutations(0,nums);
        return ans;
    }
};