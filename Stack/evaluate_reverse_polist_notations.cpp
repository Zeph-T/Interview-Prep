class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        int i;
        for(string token : tokens){
            if(token == "-"){
                if(st.size() >=2){
                    string top1 = st.top();
                    st.pop();
                    string top2 = st.top();
                    st.pop();
                    st.push(to_string(stoi(top2) - stoi(top1)) );
                }else{
                    return -1;
                }
            }else if(token == "*"){
                if(st.size() >=2){
                    string top1 = st.top();
                    st.pop();
                    string top2 = st.top();
                    st.pop();
                    st.push(to_string(stoi(top1) * stoi(top2)));
                }else{
                    return -1;
                }
            }else if(token == "+"){
                if(st.size() >=2){
                    string top1 = st.top();
                    st.pop();
                    string top2 = st.top();
                    st.pop();
                    st.push(to_string(stoi(top2) + stoi(top1)) );
                }else{
                    return -1;
                }
            }else if(token == "/"){
                if(st.size() >=2){
                    string top1 = st.top();
                    st.pop();
                    string top2 = st.top();
                    st.pop();
                    st.push(to_string(stoi(top2)/stoi(top1)) );
                }else{
                    return -1;
                }
            }else{
                st.push(token);
            }
        }
        return stoi(st.top());
    }
};