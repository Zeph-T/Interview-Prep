class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int i=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '(')st.push(i);
            else if(s[i] == ')'){
                if(!st.empty() and s[st.top()] == '(')st.pop();
                else st.push(i);
            }
        }
        while(st.size() > 0){
            s[st.top()] = '#';
            st.pop();
        }
        s.erase(remove(s.begin(),s.end(),'#'),s.end());
        return s;
    }
};