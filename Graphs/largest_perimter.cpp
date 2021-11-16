/*
we add 4 to the each grid which is 1, and check the previously visited bidirectional coordinates i.e
the top and left coordinates, if any of them are 1, means that they are connected and they share a common
side. snce we added 4 to that previous part and now they are connected, the side reduces for both
grids so we substract 2
*/


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        if(m == 0)return 0;
        int ans = 0;
        int n = grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    ans += 4;
                    if(i > 0 and grid[i-1][j] == 1)ans -= 2;
                    if(j > 0 and grid[i][j-1] == 1)ans -= 2;
                }
            }
        }
        return ans;
    }
};