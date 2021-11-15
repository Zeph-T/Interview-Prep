class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;        
        ans.push_back({1});
        if(numRows == 1)return ans;
        ans.push_back({1,1});
        if(numRows == 2)return ans;
        
        for(int i=2;i<numRows;i++){
            int rows = i +1;
            vector<int>temp(rows);
            temp[0] = 1;
            temp[rows-1] = 1;
            for(int j=1;j<rows-1;j++){
                temp[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};