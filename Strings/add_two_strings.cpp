class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = 0;
        int j = 0;
        int n1 = num1.size();
        string res="";
        int n2 = num2.size();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        while(i < n1 or j < n2){
            int pos1 = ( i < n1) ? (num1[i] - '0') : 0;
            int pos2 = (j < n2) ? (num2[j] - '0' ) : 0;
            int digit = pos1 + pos2 + carry;
            carry = digit/10;
            digit = digit%10;
            res += to_string(digit);
            i++;
            j++;
        }
        if(carry > 0)res+=to_string(carry);
        reverse(res.begin(),res.end());
        return res;
    }
};