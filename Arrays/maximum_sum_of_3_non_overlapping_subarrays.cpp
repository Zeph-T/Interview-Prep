class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>left(n,0) , right(n,0) , prefix(n,0);
        int sum = 0;
        for(int i=0;i<n;i++){ // prefix sum
            prefix[i] = i == 0 ? arr[i] : arr[i] + prefix[i-1]; 
        } 
        for(int i=0;i<n;i++){ // prefix of left max
            if(i < k){
                sum += arr[i];
                left[i] = sum;
            }else{
                sum += arr[i] - arr[i-k];
                left[i] = max(left[i-1] , sum);
            }
        }
        sum =  0; // prefix of right max
        for(int i=n-1;i>=0;i--){
            if(i+k >= n){
                sum += arr[i];
                right[i] = sum;
            }else{
                sum += arr[i] - arr[i + k];
                right[i] = max(sum , right[i+1]);
            }
        }
        
        
        
        int maxSum = 0;
        int middle_start = -1;
        int left_start = -1;
        int right_start = -1;
        int lsum = 0;
        int rsum = 0;
        vector<int>ans{-1,-1,-1};
        for(int i=k;i<= n - 2* k; i++){ // find the middle subarray of size k which maximises the ans
            int current_sum =  left[i-1] + right[i+k] + prefix[i+k -1] - prefix[i-1];
            if(current_sum > maxSum){
                maxSum = current_sum;
                lsum  = left[i-1];
                rsum  = right[i+k];
                middle_start = i;
            }
        }
        
        for(int i=k-1;i<middle_start;i++){ // find the left subarray considering the end point
            if(lsum == prefix[i] - (i - k < 0 ? 0 : prefix[i-k])){
                left_start = i - k + 1;
                break;
            }
        }
   
        for(int i=middle_start + 2 * k - 1; i < n ; i++){ // find the right subarray considering the end point 
            if(rsum == (prefix[i] - (prefix[i-k]))){
                right_start = i - k + 1;
                break;
            }
        }     
        

        return {left_start, middle_start , right_start};
    }
};