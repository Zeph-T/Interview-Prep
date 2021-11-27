class Solution {
public:
    vector<vector<int>>ans;
    void backtrack(vector<int>arr,int position , int target ,int current_sum,vector<int>&temp){
        if(current_sum > target)return ;
        if(position == arr.size())return ;
        if(current_sum == target){
            ans.push_back(temp);
            return ;
        }
        for(int i = position;i < arr.size() ;i++){
            current_sum += arr[i];
            temp.push_back(arr[i]);
            backtrack(arr,i,target,current_sum,temp);
            temp.pop_back();
            current_sum -= arr[i];
        }
        return ;
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        backtrack(candidates,0,target,0,temp);
        return ans;
    }
};