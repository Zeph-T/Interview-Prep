class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<string,int>seen;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    
                    char ch = board[i][j];
                    string foundInBox = "",foundInRow = "",foundInCol = "";
                    foundInBox.push_back(ch);
                    foundInRow.push_back(ch);
                    foundInCol.push_back(ch);
                    
                    foundInBox += " found in box " + to_string(i/3) + "-" + to_string(j/3);
                    foundInRow += " found in row " + to_string(i);
                    foundInCol += " found in col " + to_string(j);
                    
                    
                    if(seen.count(foundInRow) or seen.count(foundInCol) or seen.count(foundInBox))return false;
                    seen[foundInRow]++;
                    seen[foundInCol]++;
                    seen[foundInBox]++;
                }
            }
        }
        
        return true;
        
        
    }
};