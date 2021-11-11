class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool column = false;
        for(int i=0;i<rows;i++){ 
            if(matrix[i][0] == 0)
                column = true; // if the first column has zero.
            for(int j=1;j<cols;j++){
                if(matrix[i][j] == 0){ // if the value is zero, mark the first column of the row and first row of column as zero
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<rows;i++){
            for(int j=1;j<cols;j++){
                if(matrix[i][0] == 0 or matrix[0][j] == 0)matrix[i][j] = 0; // check if the first row of the column or first column of the row is zero 
            }
        }
        
        if(matrix[0][0] == 0) // since the first row can be an exception, the only value which can determine if the first row values are zero are not, is the first element itself.
            for(int i=0;i<cols;i++)
                matrix[0][i] = 0;
        
        if(column){ // if the first column has any zero , that has to be changed to zeros as well
            for(int i=0;i<rows;i++)
                matrix[i][0] = 0;
        }
    }
};