/*
Time Complexity = O(N  * log(max(matrix) - min(matrix)));
Space Complexity = O(1),
other approach will be is to make a min heap and traverse through the columns
*/


class Solution {
public:
    
    int countLessEqual(int num,vector<vector<int>>matrix){ // get the total number of elements less than the number in  the each row
        int count = 0;
        for(auto row : matrix){
            int left = 0;
            int right = matrix.size();
            while(left < right){
                int mid = left + (right - left)/2;
                if(row[mid] <= num)left = mid+1;
                else right = mid;
            }
            count+=left;
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int end = matrix[n-1][n-1];
        int start = matrix[0][0];
        while(end > start){
            int mid = start + (end - start)/2;
            if(countLessEqual(mid,matrix) < k)start = mid+1; // ig the number of elemenets less that the number is greater than k,we decrease the range, else increase
            else end = mid;
        }
        return start;
    }
};


/*
Time Complexity : O(N * (log(max(matrix) - min(matrix))));
Space Complexity : O(1);
*/


class Solution {
public:
    
    int countLessEqual(int num,vector<vector<int>>matrix){
        int count = 0;
        for(int i=0;i < matrix.size();i++){
            count += upper_bound(matrix[i].begin() , matrix[i].end() , num) - matrix[i].begin();
        }
        return count;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int end = matrix[n-1][n-1];
        int start = matrix[0][0];
        while(end > start){
            int mid = start + (end - start)/2;
            if(countLessEqual(mid,matrix) < k)start = mid+1;
            else end = mid;
        }
        return start;
    }
};