/*
Time Complexity : O(NlogN)
Space Complexity : O(N)
*/

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,pair<int,int>>map;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(map.count(s[i]) > 0){
                map[s[i]].second = i;                
            }else{
                map[s[i]] = {i,i};
            }
        }
        
        vector<vector<int>>intervals;
        for(auto x : map){
            intervals.push_back({x.second.first,x.second.second});
        }
        
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        n = intervals.size();
        for(auto interval  :intervals){
            if(ans.size() == 0){
                ans.push_back(interval);
            }else{
                int endTimeOfPreviousInterval = ans.back()[1];
                if(endTimeOfPreviousInterval >= interval[0]){
                    ans.back()[1] = max(interval[1],ans.back()[1]);
                    
                 }else{
                    ans.push_back(interval);
                }
            }
        }
        vector<int>res;
        for(auto x : ans){
            res.push_back(x[1] - x[0] + 1);
        }
        return res;
        
        
    }
};








/*
Time Complexity : O(N)
Space Complexity : O(1)
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int arr[128];
        int n = s.size();
        memset(arr , -1 , sizeof(arr));
        for(int i=0;i<n;i++){
            arr[s[i]] = i;
        }
        int pos = 0 , j = 0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            j  = max(j , arr[s[i]]); // the last occurence of character scanned till now
            if(i == j){
                ans.push_back(i - pos + 1);
                pos = i + 1;
            }
        }
        
        return ans;
        
    }
};