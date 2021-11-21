/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/


class Solution {
public:
    struct Comperator{
        bool operator()(Interval &a,Interval &b){
            return a.start > b.start;
        }
    };
    
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        priority_queue<Interval , vector<Interval> ,Comperator >pq;
        for(auto employee : schedule){
            for(auto interval : employee){
                pq.push(interval);
            }
        }
        
        int endTime = pq.top().end;
        pq.pop();
        vector<Interval>ans;
        while(!pq.empty()){
            int startCurrent = pq.top().start;
            if(startCurrent > endTime){
                ans.push_back({endTime , startCurrent});
            }
            endTime = max(endTime , pq.top().end);
            pq.pop();
        }
        
        return ans;
    }
};