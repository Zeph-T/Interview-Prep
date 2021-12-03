class Solution {
public:
    
    int firstNegativeInteger(vector<int>arr){
        int start = 0;
        int end = arr.size() - 1;
        int index = -1;
        while(start <= end){
            int mid = (start + end)/2;
            if(arr[mid] < 0){
                index = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
        }
        return index == -1 ? arr.size() : index;
    }
    
    
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(int row = 0;row < grid.size(); row++){
            count += grid[row].size() - firstNegativeInteger(grid[row]);
        }
        return count;
    }
};