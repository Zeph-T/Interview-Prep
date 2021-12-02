class Solution {
public:
    bool isValid(vector<int>arr , int k,int limit){
        int count = 0;
        int i = 0;
        int j=0;
        int n = arr.size();
        while(i < n or j < n){
            while(j < n  and arr[j] - arr[i] <= limit)j++;
            count+=(j - i - 1);
            i++;            
        }
        return count >= k;
    }
    
    
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = nums[n-1] - nums[0];
        while(left < right){
            int mid = (left + (right - left)/2);
            if(isValid(nums,k,mid)){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        return left;
    }
};