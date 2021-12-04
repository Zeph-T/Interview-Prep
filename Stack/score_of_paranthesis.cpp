/*
Time Complexity : O(N)
Space Complexity : O(N)

*/
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        stack<int>st;
        for(char ch  :s){
            if(ch == '('){ // for each new opening bracket, we consider it as a new score
                st.push(score); // so we push the score we currently are
                score = 0; // and reset the score
            }else{
                int top = st.top();st.pop(); // the top element would be zero if they are nested paranthesis,else would return an integer
                score  = top + max(1 , score * 2); // this will take care of two different paranthesis ()() -> would have 2 
            }
        }
        return score;
    }
};


/*
Time Complexity : O(N)
Space Complexity : O(1)

*/


class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int count = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '(')count++;
            else{
                count--;
                if(s[i-1] == '(')score += (1 << count);
            }
        }
        return score;
    }
};