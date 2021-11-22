/*
Time Complexity :  O(NLogN)
Space Complexity : O(N)
*/


class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        if(a[0] == b[0])return a[1] < b[1];
        return a[0] < b[0];
    }
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin() , intervals.end() , comp);
        vector<vector<int>>ans;
        ans.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(ans.back()[1] >= intervals[i][0]){
                ans.back()[0] = min(ans.back()[0] , intervals[i][0]);
                ans.back()[1] = max(ans.back()[1] , intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
        
    }
};


/*
Time Complexity : O(N + LogN) ~ O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    vector<vector<int>>merge(vector<vector<int>>&intervals){
        vector<vector<int>>newIntervals;
        newIntervals.push_back(intervals[0]);
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(newIntervals.back()[1] >= intervals[i][0]){
                newIntervals.back()[0] = min(newIntervals.back()[0] , intervals[i][0]);
                newIntervals.back()[1] = max(newIntervals.back()[1] , intervals[i][1]);
            }else{
                newIntervals.push_back(intervals[i]);
            }
        }
        
        return newIntervals;
        
    }
    
    
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int lower_index = upper_bound(intervals.begin(),intervals.end() , newInterval) - intervals.begin();
        vector<vector<int>>newintervals;
        int i = 0;
        for(i=0;i<lower_index;i++)newintervals.push_back(intervals[i]);
        newintervals.push_back(newInterval);
        for(i=lower_index;i<n;i++)newintervals.push_back(intervals[i]);
        return merge(newintervals);
    }
}; 

