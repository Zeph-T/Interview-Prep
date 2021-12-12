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


class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        priority_queue<int,vector<int> , greater<int>>pq;
        pq.push(intervals[0][1]);
        for(int i=1;i<n;i++){
            int end = pq.top();
            if(intervals[i][0] >= end)pq.pop();
            pq.push(intervals[i][1]);
        }
        return pq.size();
    }
};