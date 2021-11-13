class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)return ;
        for(int i=0;i<rows;i++){ // the transpose of matrix will give us the rotated matrix by 90 degrees anticlockwise
            for(int j=0;j<i;j++)swap(matrix[i][j] , matrix[j][i]);
        }
        
        for(int i=0;i<rows;i++)
            reverse(matrix[i].begin(),matrix[i].end()); // just reverse the rows to get the rotated matrix by 90 degrees anticlockwise 
        
    }
};