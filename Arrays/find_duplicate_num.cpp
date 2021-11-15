

// Approach 1 : marking negativez
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0;
        for(int i=0;i<nums.size();i++){ 
            int num = abs(nums[i]);
            if(nums[num] < 0){
                dup = num;
                break;
            }
            nums[num] = nums[num] * -1;
        }
        for(int &num : nums)num = abs(num);
        
        return dup;
    }
};