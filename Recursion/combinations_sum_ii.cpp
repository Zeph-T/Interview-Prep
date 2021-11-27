class Solution {
public:
    vector<vector<int>>ans;
    vector<int>temp;
    
    void backtrack(vector<int>nums , int position , int current_sum , int target){
        if(current_sum == target){
            ans.push_back(temp);
            return ;
        }
        
        if(current_sum > target)return; 
        for(int i=position ; i< nums.size();i++){
            if( i != position  and nums[i] == nums[i-1])continue;
            temp.push_back(nums[i]);
            backtrack(nums,i+1,current_sum + nums[i], target);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,0,0,target);
        return ans;
    }
};