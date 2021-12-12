class Solution {
public:
    int count = 0;
    int n ;
    
    void merge(vector<int>&nums,int left,int mid, int right){
        int i = left;
        int j = mid+1;
        while(i <= mid and j <= right){
            if((long)(nums[i]) > (long)(nums[j]) * 2){
                count += (mid - (i - 1));
                j++;
            }else{
                i++;
            }
        }
        sort(nums.begin() + left , nums.begin() + right + 1);
    }
    
    
    void mergeSort(vector<int>&nums,int left , int right){
        if(left >= right)return ;
        int mid = (left + right)/2;
        
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
        
    }
    
    int reversePairs(vector<int>& nums) {
        n = nums.size();
        mergeSort(nums,0,n-1);
        return count;
    }
};