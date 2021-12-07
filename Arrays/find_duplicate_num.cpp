

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


/*
Hair and Tortoise Method
Time Complexity : O(N)
Space Complexity : O(1)
The cycle appears because nums contains duplicates. The duplicate node is a cycle entrance.
--------------------------------------------

tortoise has travelled half distance as hare
so 2(F + a) = F + nC + a
The distance travelled by Tortoise = F + a
Distance travelled by Hare = 2 * (F + a) which is also equal to F + n * (length of Cycle) + a where n E [0,inf]
        a
     -----* -> Tortoise and hare meet
 F  /     \
----        ----
    \_____/

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return fast;
        
        
    }
};