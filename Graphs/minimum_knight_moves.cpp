class Solution {
public:
    int directions[8][2] = {{2,-1} , {2, 1} , {1,2} , {-1,2} , {-2,1} , {-2, -1} , {-1, -2} , {1 ,-2}};
    int minKnightMoves(int x, int y) {
        x = abs(x);
        y = abs(y);
        queue<pair<int,int>>q;
        q.push({0,0});
        set<pair<int,int>>visited;
        visited.insert({0,0});
        int moves = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int x1 = q.front().first;
                int y1 = q.front().second;
                q.pop();
                if(x1 == x and y1 == y)return moves;
                for(int k=0;k<8;k++){
                    int newX = x1 + directions[k][0];
                    int newY = y1 + directions[k][1];
                    if(newX>=-1 and newY>=-1 and visited.find({newX,newY}) == visited.end()){
                        q.push({newX,newY});
                        visited.insert({newX,newY});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};