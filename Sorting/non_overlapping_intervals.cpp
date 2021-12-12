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

/*
Time Complexity : O(NLogN)
Space Complexity : O(1)
*/


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int prevIndex = 0;
        int count = 0;
        int n = intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[prevIndex][1] > intervals[i][0]){ // if the start of the new interval is less than the end of the prev interval, we have to remove that
                count++;
                if(intervals[prevIndex][1] > intervals[i][1]){ // just in case the new interval has less end time, we have to update the prevIndex because we want to 
                    prevIndex = i;                              // the least interval which would be possible for overlapp
                }
            }else{
                prevIndex = i;
            }
        }
        return count;
    }
};