class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int carry = 0;
        digits[len - 1] += 1;
        if(digits[len - 1] >= 10){
            int carry = digits[len - 1]/10;
            digits[len - 1] = digits[len - 1]%10;
            len--;
            while(len >= 1 and carry > 0){
                digits[len - 1] += carry;
                carry = digits[len - 1]/10;
                digits[len -1] = digits[len - 1]%10;
                len--;
            }
            if(carry > 0){
                digits.insert(digits.begin() , 1 , carry);
            }
        }
        return digits;
    }
};s