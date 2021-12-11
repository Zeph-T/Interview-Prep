class Solution {
public:
    int count = 0;
    
    
    bool validDigit(int num){
        int digit[10];
        memset(digit,0,sizeof(digit));
        
        while(num){
            digit[num%10]++;
            num = num/10;
        }
        
        for(int i=0;i<10;i++){
            if(digit[i] and (i == 3 or i == 4 or i == 7))return false;
        }
        
        
        for(int i=0;i<10;i++){
            if(digit[i] and i != 0 and i != 1 and i != 8)return true;
        }
        return false;
        
        
    }
    
    int rotatedDigits(int n) {
        for(int i=2;i<=n;i++){
            if(validDigit(i))count++;
        }
        return count;
    }
};