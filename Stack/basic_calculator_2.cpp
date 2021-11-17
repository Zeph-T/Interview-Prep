class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        stack<int>st;
        char sign = '+';
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(isdigit(ch)){
                int val = 0;
                while(i < n and isdigit(s[i])){
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                if(sign == '+')st.push(val);
                else if(sign == '-')st.push(-val);
                else if(sign == '*'){
                    int top = st.top();
                    st.pop();
                    st.push(val * top);
                }else if(sign == '/'){
                    int top = st.top();
                    st.pop();
                    st.push(top/val);
                }
            }else if(ch == '+' || ch == '-' || ch == '/' || ch == '*')sign = ch;
        }
        int ans = 0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};