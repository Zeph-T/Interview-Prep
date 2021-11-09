class Solution {
public:
    bool isPossible(vector<int>&weights,int sum,int days){
        int limit = 1;
        int curr_sum = 0;
        int n = weights.size();
        for(int i=0;i<n;i++){
            if(weights[i] > sum)return false;
            if(weights[i] + curr_sum > sum){
                curr_sum = weights[i];
                limit++;
                if(limit > days)return false;
                
            }else{
                curr_sum += weights[i];
            }
        }
        return true;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        if(n < days)return -1;
        int left = *max_element(weights.begin(),weights.end());
        int right = 0;
        for(int weight : weights)right+=weight;
        int ans = -1;
        while(left <= right){
            int mid = left + (right - left)/2;
            if(isPossible(weights,mid,days)){
                ans = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return ans;
    }
};