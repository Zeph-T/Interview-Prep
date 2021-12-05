
/*
Approach 1 : Using Recursion and memoization
Time Complexity : O(W) W = 365;
Space Complexity ; O(N)
*/

class Solution {
public:
    int dp[366];
    
    bool willTravelToday(int day , vector<int>days){
        int left = 0;
        int right = days.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(days[mid] == day)return true;
            else if(days[mid] > day)right = mid-1;
            else left = mid+1;
        }
        return false;
    }
    
    
    int solve(int day , vector<int>costs,vector<int>days){
        
        if(day > days[days.size() - 1])return 0;
        if(dp[day] != -1)return dp[day];
        int ans = INT_MAX;
        if(willTravelToday(day,days)){ // if the person travels today, we have to check for the next case till any three passes will be valid
            ans = solve(day  +1 , costs,days) + costs[0];
            ans = min(ans , solve(day + 7 , costs , days) + costs[1]);
            ans = min(ans , solve(day + 30 , costs,days)  + costs[2]);
        }else{
            return dp[day] = solve(day + 1 , costs , days); // the same as the previous cost
        }
        
        return dp[day] = ans;
    }
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        int n = days.size();
        return solve(days[0] , costs , days);
    }
};


