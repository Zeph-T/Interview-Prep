class Solution {
public:
    vector<string>ans;
    
    void backtrack(string curr,int opens,int close,int limit){
        if(curr.size() == 2 * limit){
            ans.push_back(curr);
            return ;
        }
        if(opens < limit){ // we can add the open bracket till we reach the limit
            curr += '(';
            backtrack(curr,opens+1,close,limit);
            curr.pop_back();
        }
        if(close < opens){ // we can add the close bracket as long as it does not goes beyond the open brackets
            curr += ')';
            backtrack(curr,opens,close+1,limit);
            curr.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int n) {
        string curr="";
        backtrack("",0,0,n);
        return ans;
    }
};