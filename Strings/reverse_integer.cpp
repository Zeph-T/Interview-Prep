
/*
Time Complexity = O(N/2)
Space Complexity = O(1)
*/

class Solution {
public:
    int reverse(int x) {
        string max_val = "2147483647"; // max_val 
        bool negative = false;
        if(x < 0)negative = true;
        x = abs(x);
        string str = to_string(x);
        for(int i=0;i<str.size()/2;i++){
            swap(str[i] , str[str.size() - i - 1]);
        }

        if(str.size() > 10){
            return 0;
        }
        int len = str.size();
        if(str.size() == 10){
            for(int i=0;i<10;i++){
                if(str[i] == max_val[i])continue;
                else if(str[i] > max_val[i])return 0;
                else{
                    break;
                }
            }
        }
        
        return negative ? -stoi(str) : stoi(str);
        
        
    }
};


/*

Time Complexity : O(LogN)
Space Complexity : O(1)
*/


class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while(x!=0){
            int remainder = x%10;
            if(num > INT_MAX/10 or (num == INT_MAX/10 and remainder > 7))return 0;
            if(num < INT_MIN/10 or (num == INT_MIN/10 and remainder < -8))return 0;
            num = num * 10 + remainder;
            x = x/10;
        }
        return num;
    }
};