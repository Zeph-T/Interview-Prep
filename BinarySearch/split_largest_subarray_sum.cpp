class Solution {
public:
    
    bool possible(vector<int>nums,int target , int m){
        int count = 1;
        int sum = 0;
        for(int num : nums){
            if(sum + num > target){
                sum = num;
                count++;
            }else{
                sum = sum + num;
            }
        }
        return count > m;
    }
    int splitArray(vector<int>& nums, int m) {
        int start = *max_element(nums.begin(),nums.end()); // the max_element will be the least possible answer when m =1
        int end = accumulate(nums.begin(),nums.end(),0); //the sum of elements will be the largest possible answer when m = n
         
        while(start < end){
            int mid = (start + end)/2;
            if(possible(nums,mid,m)){
                start = mid + 1;
            }else{
                end = mid;
            }
        } 
        return end;
        
        
    }
};