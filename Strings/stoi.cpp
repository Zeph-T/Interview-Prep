class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int n = s.size();
        for(i=0;i<n;i++){
            if(s[i] == ' ')continue;
            else break;
        }
        bool neg = false;
        if(s[i] == '-'){
            neg = true;
            i++;
        }else if(s[i] == '+')i++;
        
        int ans = 0;
        for(int j=i;j<n;j++){
            if(s[j] >= '0' and s[j] <= '9'){
                if(ans > INT_MAX / 10 || (ans == INT_MAX /10 && (s[j]-'0') > 7)) // check if the ans when multiplied by 10, which we will be doing in the next instruction is overflow, or if the ans has reached the limit i.e INT_MAX and the digit is > 7 as 2^32-1 value is 2147483647, will cause the overflow
                    return neg ? INT_MIN : INT_MAX;
                ans = ans * 10 + (s[j] - '0');
            }else{
                break;
            }
        }
        return neg ? -ans : ans;
        
    }
};