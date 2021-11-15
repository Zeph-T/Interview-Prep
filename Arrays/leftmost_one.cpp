int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n == 0)return -1;
    int m = matrix[0].size();
    int i = 0;
    int j = m-1; // start from the top right corner
    int ans = -1;
    while(i < n and j >= 0 ){
        if(matrix[i][j] == 1){ // means 1 is present in this col, so start looking at the prev col
            ans = j;
            j--;
        }else i++; // one is not found, go deep in that column
    }   
    return ans;
}