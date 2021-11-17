class Solution {
public:
    int calculate(string s) {
        int sum  = 0;
        stack<int>st;
        int sign = 1;
        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(isdigit(ch)){
                int val = 0;
                while(i < s.size() and isdigit(s[i])){
                    val = val * 10 + (s[i] - '0');
                    i++;
                }
                i--;
                val = val *sign;
                sum += val;
                sign = 1;
            }else if(ch == '('){
                st.push(sum);
                st.push(sign);
                sum = 0;
                sign = 0;
            }else if(ch == ')'){
                int topsign = st.top();st.pop();
                int topval = st.top(); st.pop();
                sum  = sum * topsign;
                sum += topval;

            }else if(ch == '-'){
                sign = sign * -1;
            }
        }
        return sum;
    }
};

/*   7 -1
 (1 + 2 + 4)
*/