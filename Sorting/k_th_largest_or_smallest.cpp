class Solution {
public:
    int partition(vector<int> &a,int s,int e){

    int pivot = a[e];
    int i = s - 1;

    for(int j=s;j<e;j++){
        if(a[j] < pivot){
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[e]);
    return i + 1;

    }

    int quickselect(vector<int> a, int s,int e,int k){
    int p = partition(a,s,e);
    if(p==k){
        return a[p];
    }
    else if(k<p){
        return quickselect(a,s,p-1,k);
    }		
    else{
        return quickselect(a,p+1,e,k);
    }

    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums,0,nums.size()-1,n-k);
    }
};