
/*
Time Complexity : O(N)
Space Complexity : O(N)
*/

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


/*
Time Complexity : O(N)
Space Complexity : O(1)

*/


class Solution {
public:
        string minRemoveToMakeValid(string s)
        {
            int count = 0;
            int n = s.size();
            for(int i=0;i<n;i++){
                if(s[i] == '(')count++;
                else if(s[i] == ')'){
                    if(count == 0)s[i] = '#';
                    else count--;
                }
            }
            
            count = 0;
            for(int i=n-1;i>=0;i--){
                if(s[i] == ')')count++;
                else if(s[i] == '('){
                    if(count == 0)s[i] = '#';
                    else count--;
                }
            }
            string res="";
            for(char ch : s){
                if(ch != '#')res+=ch;
            }
            return res;
        }
};