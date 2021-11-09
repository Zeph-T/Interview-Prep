class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] =='(')st.push(s[i]);
            else{
                if(st.size() > 0 and s[i] == ')' and st.top() == '(')st.pop();
                else{
                    st.push(s[i]);
                }
            }
        }
        return st.size();
    }
};