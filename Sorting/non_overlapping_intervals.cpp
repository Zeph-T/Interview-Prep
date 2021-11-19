class Solution {
public:
    
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end() , comp); // greedy sort based on the end time
        int n = intervals.size();
        int count = 1;
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] >= end){ // if the start time of the next interval is greater than the end time, means no intersection
                end = intervals[i][1];
                count++;
            }
        }
        return n -  count; // total - no intersection = intersections
    }
};