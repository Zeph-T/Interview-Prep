class Solution {
public:
    
    bool isValid(int limit,int h,vector<int>piles){
        int count = 0;
        for(int pile : piles){
            count += (pile/limit);
            if(pile%limit)count++;
        }
        return count <= h;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = *max_element(piles.begin(),piles.end());
        int ans = -1;
        if(piles.size() == h)return end;
        while(start <= end){
            int mid = start  + (end - start)/2;
            if(isValid(mid,h,piles)){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return ans;
        
        
    }
};