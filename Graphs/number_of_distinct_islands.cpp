class Solution {
public:
    set<string>answers;
    vector<vector<int>>grid;
    int rows = 0;
    int cols = 0;
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    char directions[4] = {'L','R','U','D'};
    
    
    bool isValid(int row,int col){
        if(row < 0 or row >= rows or col < 0 or col >= cols)return false;
        return true;
    }
    
    
    string dfs(int row,int col,char direction){
        if(!isValid(row,col))return "";
        if(grid[row][col] == 0)return "";
        grid[row][col] = 0;
        string res="";
        res+=direction;
        for(int k=0;k<4;k++){
            int x = dx[k] + row;
            int y = dy[k] + col;
            res+=dfs(x,y,directions[k]);
         }
        
        res+='B';
        return res;
    }
    
    
    
    int numDistinctIslands(vector<vector<int>>& gridss) {
        this->grid = gridss;
        int rows = grid.size();
        int cols = grid[0].size();
        this->rows = rows;
        this->cols = cols;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == 1){
                    string temp = dfs(i,j,'S');
                    cout<<temp<<endl;
                    answers.insert(temp);     
                }
            }
        }
        return answers.size();
    }
};