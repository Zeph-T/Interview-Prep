/*
TLE Approach
Time Complexity : O(N^2)
Space Complexity : O(N)
*/


class Solution {
public:
    static bool comp(vector<int>&a,vector<int>&b){
        return a[1] < b[1];
    }
    
    
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end(),comp);
        int n = events.size();
        int max_day = INT_MIN;
        for(int i=0;i<n;i++){
            max_day = max(max_day , events[i][1]);
        }
        int i=0;
        vector<bool>visited(max_day+1,false);
        for(auto event : events){
            int start = event[0];
            int end = event[1];
            while(start <= end){
                if(visited[start] == false){
                    visited[start] = true;
                    break;
                }
                else start++;
            }
        }
        
        int count = 0;
        for(bool allocated : visited)if(allocated)count++;
        return count;
    }
};






/*
Optimised Approach
Time Complexity : O(NlogN)
Space Complexity : O(N)
*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin() , events.end());
        priority_queue<int,vector<int> , greater<int>> pq;
        int n = events.size();
        int pos = 0;
        int ans = 0;
        int day ;
        while(pq.size() > 0 or pos < n){
            if(pq.size() == 0)day = events[pos][0]; // initial event, we just attend
            
            while(pos < n and events[pos][0] == day)pq.push(events[pos++][1]); // we push all the end time of events that start on the particular day
            pq.pop();
            ans++; // we attend the event
            day++; // so next time we have to consider for the next day
            while(pq.size() > 0 and pq.top() < day)pq.pop(); // removing all the events that end on or before the present day
        }
        return ans;
    }
};