class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int end = n-1;
        int start = 0;
        while(start <= end){
            int mid = start + (end - start)/2;
            int missingElements = arr[mid] - mid - 1;
            if(missingElements >= k){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return start + k;
    }
};