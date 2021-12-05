/*
Time Complexity : O()

*/


class Solution {
public:
    unordered_map<string,bool>dp;
    unordered_set<string>visited;
    
    bool isPalindrome(string s){
        int j = s.size() - 1;
        int i = 0;
        while(i < j){
            if(s[i++] != s[j--])return false;
        }
        return true;
    }
    
    
    
    bool dfs(string s,int count,int limit){
        if(visited.count(s) > 0)return false;
        if(count > limit)return false;
        if(dp.count(s) > 0)return dp[s];
        
        
        if(count <= limit){
            if(isPalindrome(s)){
                return true;
            }
        }
        
        for(int i=0;i<s.size();i++){
            bool possible = dfs(s.substr(0,i) + s.substr(i+1) , count+1,limit);
            if(possible)return dp[s] = true;
        }
        return dp[s] = false;
        
    }
    
    
    bool isValidPalindrome(string s, int k) {
        return dfs(s,0,k);
    }
};


/*
Approach 2 : 
Recursion + Memoization
Time Complexity : O(N^2)
Space Complexity : O(N^2)
*/
class Solution {
public:
    vector<vector<int>>dp;
    
    int check(int start, int end, string &s,vector<vector<int> > &dp){
        if(start>end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        if(s[start] == s[end]) return dp[start][end] = check(start+1,end-1,s,dp);
        else return dp[start][end] = 1+min(check(start+1,end,s,dp) , check(start,end-1,s,dp));
    }
    
    
    bool isValidPalindrome(string s, int k) {
        int start= 0;
        int end = s.length()-1;
        vector<vector<int> > dp(end+1,vector<int>(end+1,-1));
        return check(start,end,s,dp) <= k;
    }
};