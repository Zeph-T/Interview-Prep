class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        if(n == 0)return true;
        int endTime = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < endTime)return false;
            endTime = max(endTime , intervals[i][1]);
        }
        return true;
            
    }
};