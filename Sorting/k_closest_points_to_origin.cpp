class Solution {
public:
    
    int distance(vector<int>point){
       return point[0]*point[0] + point[1]*point[1];
    }
    
    
    int partition(vector<vector<int>>&points,int left,int right){
        vector<int> pivot = points[right];
        int i = left;
        for(int j = left;j<right ;j++){
            if(distance(points[j]) <= distance(pivot)){
                swap(points[i] , points[j]);
                i++;
            }
        }
        
        swap(points[i] , points[right]);
        return i;
    }

    
    int quickSelect(vector<vector<int>>&points,int left,int right,int k){
        if(left <= right){
            int pivot = partition(points,left,right);
            if(pivot == k - 1)return pivot;
            else if(pivot < k-1)return quickSelect(points,pivot+1,right,k);
            else return quickSelect(points,left,pivot-1,k);    
        }else{
            return -1;
        }

    }
    
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        int position = quickSelect(points,0,n-1,k);
        vector<vector<int>>ans;
        for(int i = 0;i<=position;i++){
            ans.push_back(points[i]);
        }
        return ans;
    }
};