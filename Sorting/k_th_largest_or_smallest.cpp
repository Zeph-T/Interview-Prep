
/*
This algorithm runs in avg case O(N) because we make recursive calls based on the parition eleement;
Time Complexity : 0(N)
Space Complexity : O(1)
*/


int partition(vector<int>&nums,int start,int end){
    int pivot = nums[end];
    int i = start;
    for(int j=start;j<end;j++){
        if(nums[j] < pivot){
            swap(nums[i],nums[j]);
            i++;
        }
    }
    swap(nums[end] , nums[i]);
    return i;
}



int quickSelect(vector<int>&nums,int start,int end,int k){
    int p = partition(nums,start,end);
    if(p == k)return nums[k];
    else if(k < p)return quickSelect(nums,start,p-1,k);
    else return quickSelect(nums,p+1,end , k);
}


int solve(vector<int>& nums, int k) {
    return quickSelect(nums,0,nums.size()-1,k);
}