/**
 *Approach DFS
 Space Complexity : O(N)
 Time Complexity : O(N)
 */
class Solution {
public:
    
    int solve(vector<NestedInteger>&list,int depth){
        int total = 0;
        for(NestedInteger nested : list){
            if(nested.isInteger())total+=(nested.getInteger() * depth);
            else total += solve(nested.getList() , depth+1);
        }
        return total;
    }
    
    int depthSum(vector<NestedInteger>& nestedList) {
        return solve(nestedList,1);
    }
};




/**
Approach : BFS
Time Complexity : O(N)
Space Complexity : O(N)
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger>q;
        for(NestedInteger list : nestedList)q.push(list);
        int total = 0;
        int depth = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                NestedInteger nested = q.front();
                q.pop();
                if(nested.isInteger()){
                    total += nested.getInteger() *depth;
                }else{
                    for(NestedInteger deep : nested.getList()){
                        q.push(deep);
                    }
                }
            }
            depth++;
        }
        
        return total;
    }
};