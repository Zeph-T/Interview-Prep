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
                }else{class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int n1  = word.size();
        int n2 = abbr.size();
        while(i < n1 and j < n2 ){
            if(abbr[j] == '0')return false;
            if(isdigit(abbr[j])){
                int num = 0;
                while(isdigit(abbr[j])){
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i+=num;
            }else{
                if(word[i] == abbr[j]){
                    i++;j++;
                }else{
                    return false;
                }
            }
        }
        if(i == n1 and j == n2)return true;
        return false;
    }
};
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