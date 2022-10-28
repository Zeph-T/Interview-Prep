#include <bits/stdc++.h>
using namespace std;


void recur(int row,int col,string word,vector<vector<char>>&grid,int pos,vector<pair<int,int>>&ans,vector<pair<int,int>>temp){
    if(pos == word.size()){
        ans = temp;
        return ;
    }
    char ch = word[pos];

    int dx[4] = {1,0};
    int dy[4] = {0,1};

    for(int k = 0 ; k < 2 ; k++){
        int newX = dx[k] + row;
        int newY = dy[k] + col;
        if(newX >= 0 and newX < grid.size() and newY >= 0 and newY < grid[0].size() and ch == grid[newX][newY]){
            temp.push_back({newX,newY});
            recur(newX,newY,word,grid,pos+1,ans,temp);
        }
    };


}

void findWord(string word,vector<vector<char>>grid){
    bool found = false;
    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0 ; j < grid[0].size() ; j++){
            char ch = grid[i][j];
            if(ch == word[0]){
                vector<pair<int,int>>v;
                vector<pair<int,int>>temp;
                temp.push_back({i,j});
                recur(i,j,word,grid,1,v,temp);
                if(v.size() != 0){
                    found = true;
                    for(auto x : v)cout << x.first << " " << x.second << endl;
                    break;
                }
            }
        }
    }

    if(found == false)cout << "None";
}


int main() {
    string word;
    cin >> word;
    int rows , cols;
    cin >> rows >> cols;

    vector<vector<char>>grid(rows,vector<char>(cols));
    for(int i = 0 ;i < rows; i++){
        for(int j = 0 ; j < cols ; j++){
            cin >> grid[i][j];
        }
    }

    findWord(word,grid);




}