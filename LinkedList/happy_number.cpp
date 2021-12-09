class Solution {
public:
    int next(int n){
        int total = 0;
        while(n > 0){
            int digit = n%10;
            total += pow(digit,2);
            n = n/10;
        }
        return total;
    }
    
    
    bool isHappy(int n) {
        int slow = n ;
        int fast = n;
        do{
            slow = next(slow);
            fast = next(next(fast));
        }while(slow != fast);
        
        if(slow == 1)return true;
        return false;
        
    }
};