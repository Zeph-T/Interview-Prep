class Solution {
public:
    unordered_map<int,unordered_map<int,int>>firstMap;
    unordered_map<int,unordered_map<int,int>>secondMap;
    
    
    
    void createMapRow(vector<vector<int>>&mat1){
        int rows = mat1.size();
        int cols = mat1[0].size();
        for(int row = 0 ;row < rows;row++){
            for(int col = 0; col < cols ; col++){
                if(mat1[row][col] != 0){
                    firstMap[row][col] = mat1[row][col];
                }
            }
        }
    }
    
    
    void createMapCol(vector<vector<int>>mat2){
        int rows = mat2.size();
        int cols = mat2[0].size();
        for(int col = 0 ; col < cols ;col++){
            for(int row = 0;row < rows ; row++ ){
                if(mat2[row][col] != 0){
                    secondMap[col][row] = mat2[row][col];
                }
            }
        }
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int rows1 = mat1.size();
        int cols1 = mat1[0].size();
        int rows2 = mat2.size();
        int cols2 = mat2[0].size();
        vector<vector<int>>ans(rows1,vector<int>(cols2,0));
        createMapCol(mat2);
        createMapRow(mat1);
        for(int i=0;i<rows1;i++){
            for(int j=0;j<cols2;j++){
                if(secondMap.count(j) == 0 and firstMap.count(i) == 0)ans[i][j] = 0;
                auto firstRow = firstMap[i];
                auto secondCol = secondMap[j];
                int sum = 0;
                for(auto x:  firstRow){
                    // cout<<x.first<<" "<<x.second<<endl;
                    if(secondCol.count(x.first) > 0){
                        sum += x.second * secondCol[x.first];
                    }
                }
                ans[i][j] = sum;
            }
        }
        return ans;
        
    }
};