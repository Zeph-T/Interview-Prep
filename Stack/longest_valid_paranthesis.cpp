/*
Approach 1 : use two pointers, where we keep track of the number of opens and number of closes, and reset both of them when the closes are greater than opens,same
iteration will happend in reverse as well, now, the opens act as closes and closes act as opens i.e the reset condition will be when opens are greater than closes;
Time Complexity : O(N)
Space Complexity : O(1)
*/


class Solution {
public:    
    int longestValidParentheses(string s) {
        int opens = 0;
        int ans = 0;
        int n = s.size();
        int closes=  0;
        for(char ch : s){
            if(ch == '(')opens++;
            else closes++;
            
            if(opens == closes){
                ans = max(ans , 2* opens);
            }else if(closes >= opens){
                opens = 0;
                closes = 0;
            }
        }
        opens = 0;
        closes = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '(')opens++;
            else closes++;
            
            if(opens == closes){
                ans = max(ans , 2 * opens);
            }else if(opens >= closes){
                opens = 0;
                closes = 0;
            }
        }
        return ans;
        
    }
};


/*
Use stack to keep track of the closing braces by intitally pushing -1, then for each char, we check if the char is open or close, if open, we push its index ,when close 
we check the top of the stack since that is the index for the last valid position, so the length will be i - st.top()
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int ans = 0;        
        int n = s.size();
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == '(')st.push(i);
            else{
                st.pop();
                if(st.empty())st.push(i);
                else{
                    ans = max(ans , i - st.top() );
                }
            }
        }
        return ans;
    }
};