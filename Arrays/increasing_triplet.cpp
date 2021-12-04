class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX;
        int second = INT_MAX;
        for(int num : nums){
            if(num <= first)first = num;
            else if(num <= second)second = num; // if we find both first and second max, and then find a third max, we got our answer
            else return true;
        }
        return false;
    }
};