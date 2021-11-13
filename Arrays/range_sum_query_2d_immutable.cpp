class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        mat = matrix;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++){
            for(int j=1;j<cols;j++)
                mat[i][j] += mat[i][j-1];
        }
        
        for(int i=0;i<cols;i++){
            for(int j=1;j<rows;j++){
                mat[j][i] += mat[j-1][i];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum  = mat[row2][col2]; // the complete sum from (0,0) to (row2,col2);
        sum -= (row1 >= 1) ? mat[row1-1][col2] : 0; // remove the sum till (row1,col2)
        sum -= (col1 >= 1) ? mat[row2][col1-1]  : 0; // remove the sum till (row2.col1)
        sum += (row1 >= 1 and col1 >= 1) ? mat[row1-1][col1-1] : 0; // since the part row1,col1 has been subtracted twicee
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */