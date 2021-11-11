class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0; // pointer to keep track of zeros
        int curr = 0;
        int p2 = nums.size()-1;  // pointer to keep track of twos
        while(curr <= p2){
            if(nums[curr] == 0){
                swap(nums[curr++] , nums[p0++]);  // place the zero at p0  and swap
            }else if(nums[curr] == 2){
                swap(nums[curr],nums[p2--]); // swapv the p2 pointer value with curr pos
            }else{
                curr++;
            }
        }
    }
};