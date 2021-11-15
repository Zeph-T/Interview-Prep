/*
Input: s = "3[a]2[bc]"
Output: "aaabcbc"
*/


class Solution {
public:
    string decodeString(string s) {
        stack<int> nStack;
        stack<string>res;
        string curr="";
        int idx = 0;
        int n = s.size();
        while(idx < n){
            char ch = s[idx];
            if(ch>= '0' and ch <= '9'){ // get the integer
                int count = 0;
                while(s[idx] >= '0' and s[idx] <= '9'){
                    count = count * 10 + (s[idx] - '0');
                    idx++;
                }
                nStack.push(count);
            }else if(ch == '['){ // push the current string into the stack
                res.push(curr);
                curr = "";
                idx++;
            }else if(ch == ']'){ // should append the string built until now nStack.top() times to the string which was before [ i.e the top of the res stack
                string temp = res.top();
                res.pop();
                int k = nStack.top(); 
                nStack.pop();
                for(int i=k;i>0;i--){
                    temp+=curr;
                }
                curr = temp; // the resultant string will be the new current string as it has completed decoding
                idx++;
            }else{ // add the char to the current string 
                curr+=ch;
                idx++;
            }
        }
        return curr;
    };
    
};