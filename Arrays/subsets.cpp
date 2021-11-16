class Solution {
public:
    vector<vector<int>>ans;
    
    void solve(vector<int>&nums,vector<int>temp,int index){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            temp.push_back(nums[i]); // push to the element to the vector
            solve(nums,temp,i+1); // recur for the remaining indexes
            temp.pop_back(); //backtrack
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>temp;
        solve(nums,temp,0);
        return ans;
    }
};