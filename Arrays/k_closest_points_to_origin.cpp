class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        vector<vector<int>>ans;
        int n = points.size();
        for(int i=0;i<k;i++){
            long long int x,y;
            x = pow(points[i][0],2);
            y = pow(points[i][1],2);
            pq.push({x + y,i});
        }
        for(int i=k;i<n;i++){
            long long int x,y;
            x = pow(points[i][0],2);
            y = pow(points[i][1],2);
            if(pq.top().first > x+y){
                pq.pop();
                pq.push({x+y,i});
            }
        }
        for(int i=0;i<k;i++){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};