class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i + nums[i] >= last)last = i; // check if we can reach the
            // previous position from the current position, counting backwards
        }
        return last == 0;
    }
};