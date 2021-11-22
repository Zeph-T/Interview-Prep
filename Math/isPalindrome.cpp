class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)return false;
        int num = 0 ;
        int new_num = x;
        while(x!=0){
            if(num > INT_MAX/10 or (num == INT_MAX/10 and x%10 > 7))return false;
            num = num * 10 + x%10;
            x = x/10;
        }
        return num == new_num;
    }
};