class Solution {
public:
    set<string>visited;
    vector<string>ans;
    
    int minRemoveParanthesis(string s){
        int minRemove = 0;
        int open = 0;
        for(char ch : s){
            if(ch == '(')open++;
            else if(ch == ')'){
                if(open == 0)minRemove++;
                else --open;
            }
        }
        minRemove += open;
        return minRemove;        
    }
    

    void recur(string s,int limit){
        if(visited.count(s))return ;
        visited.insert(s);
        if(limit == 0){
            if(minRemoveParanthesis(s) == 0)ans.push_back(s);
            return ;
        }
        for(int i=0;i<s.size();i++){
            if(s[i] == ')' or s[i] == '(')
                recur(s.substr(0,i) + s.substr(i+1) , limit - 1);
        }
    }
    
    
    
    vector<string> removeInvalidParentheses(string s) {
        int minRemove = minRemoveParanthesis(s);
        recur(s,minRemove);
        // vector<string>ans(result.begin(),result.end());
        return ans;
    }
};