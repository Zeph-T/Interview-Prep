class Solution {
public:
    
    int partition(vector<int>&nums,int left,int right){
        int pivotElement = nums[right];
        int i = left;
        for(int j=left;j<right;j++){
            if(nums[j] < pivotElement){
                swap(nums[j],nums[i]);
                i++;
            }
        }
        swap(nums[i],nums[right]);
        return i;
        
    }
    
    
    int quickSelect(vector<int>&nums,int left,int right,int k){
        int pivot = partition(nums,left,right);
        if(k == pivot)return pivot;
        else if(k > pivot)return quickSelect(nums,pivot+1,right,k);
        else return quickSelect(nums,left,pivot-1,k);
    }
    
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int kn = quickSelect(nums,0,n-1,n-k);
        return nums[kn];
    }
};