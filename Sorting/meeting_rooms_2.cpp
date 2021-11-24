class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int rooms = 1;
        int n = intervals.size();
        vector<int>start;
        vector<int>end;
        for(int i=0;i<n;i++){
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int p1 = 1;
        int p2 = 0;
        while(p1 < n){
            if(start[p1] >= end[p2]){
                rooms--;
                p2++;
            }
            p1++;
            rooms++;
        }
        return rooms;
    }
};