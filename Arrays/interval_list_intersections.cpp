class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& a, vector<vector<int>>&b) {
        int i=0;
        int j=0;
        int n1 = a.size();
        int n2 = b.size();
        vector<vector<int>>ans;
        while(i<n1 and j<n2){
            int lo = max(a[i][0] , b[j][0]); // get the greatest start point
            int hi = min(a[i][1] , b[j][1]); // get the smallest end point
            if(lo <= hi)ans.push_back({lo,hi}); // if the end of the smallest interval is greater than or equal to start of the greatest interval , there is an intersection
            if(a[i][1] < b[j][1])i++; //we move the one which has less end point
            else j++;
        }
        return ans;
    }
};