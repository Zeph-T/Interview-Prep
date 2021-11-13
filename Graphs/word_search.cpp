class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};
    
    bool dfs(vector<vector<char>>&board,int i,int j,int ptr,string word){
        if(ptr == word.size())return true;
        int n = board.size();
        int m = board[0].size();
        if(i >= 0 and i < n  and j >= 0 and j<m and board[i][j] == word[ptr]){ // valid traversal
            char ch = board[i][j];
            board[i][j] = '#'; // mark the node visited
            for(int k=0;k<4;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(dfs(board,x,y,ptr+1,word))return true; // found the word looking for,
            }
            board[i][j] = ch; // backtrack
            return false; 
        }else return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        if(n == 0)return false;
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == word[0] and dfs(board,i,j,0,word))return true; // no need to traverse if the first char is not the same
            }
        }
        return false;
    }
};