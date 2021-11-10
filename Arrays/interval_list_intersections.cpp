class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>&b) {
        int i=0;
        int j=0;
        int n1 = a.size();
        int n2 = b.size();
        vector<vector<int>>ans;
        while(i<n1 and j<n2){
            int lo = max(a[i][0] , b[j][0]);
            int hi = min(a[i][1] , b[j][1]);
            if(lo <= hi)ans.push_back({lo,hi});
            if(a[i][1] < b[j][1])i++;
            else j++;
        }
        return ans;
    }
};