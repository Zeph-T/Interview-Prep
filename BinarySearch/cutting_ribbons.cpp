class Solution {
public:
    bool isValid(vector<int>ribbons,int target,int k){
        int count = 0;
        for(int ribbon  :ribbons){
            count += ribbon/target;
        }
        if(count >= k)return true;
        return false;
    }
    
    
    int maxLength(vector<int>& ribbons, int k) {
        int ans = 0;
        int end = *max_element(ribbons.begin(),ribbons.end());
        int start = 0;
        while(start < end){
            int mid = (start + end +1)/2;
            if(isValid(ribbons,mid,k)){
                ans = mid;
                start = mid;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};