class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if(n == 0)return 0;
        int num = 0;
        char op = '+';
        for(int i=n-1;n>=0;i--){
            if(s[i] == ' ')n--;
            else break;
        }
        int last = 0;
        int result = 0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            if(ch == ' ')continue;
            if(ch>='0' and ch<='9'){
                num = num * 10 + (ch - '0');
            }
            if(!isdigit(ch) or i == n-1 ){
                int top;
                switch(op){
                    case '+' : result+=last;
                                last = num;
                        break;
                    case '-' : result+=last;
                                last  = -num;
                        break;
                    case '*' : last = last * num;
                        break;
                    case '/' : last = last /num;
                }
                op = ch;
                num = 0;
            }
        }
        result+=last;
        return result;
    }
};