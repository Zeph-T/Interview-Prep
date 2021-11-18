class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        if(rows == 0)return {};
        int cols = mat[0].size();
        vector<int>ans(rows * cols);
        int r = 0,c = 0;
        int total = rows * cols;
        for(int i=0;i<total;i++){
            ans[i] = mat[r][c];
            if((r + c)%2 == 0){ // if the row and col sum is even then the traversing is opposite, so we have to consider the case where if the columns become max, then we 
                                //  move to the next row, else if we are at the first row, we move to the next col, opposite for the odd case
                if(c == cols - 1){
                    r++;
                }
                else if(r == 0){
                    c++;
                }else{
                    r--;
                    c++;
                }
            }else{
                if(r == rows - 1){
                    c++;
                }else if(c == 0){
                    r++;
                }else{
                    r++;
                    c--;
                }
            }
        }
        return ans;
    }
};