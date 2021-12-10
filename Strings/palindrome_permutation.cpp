class Solution {
public:
    bool canPermutePalindrome(string s) {
        int count[128];
        memset(count,0,sizeof(count));
        int negativecount = 0;
        for(char ch : s){
            count[ch]++;
            if(count[ch]%2==0){
                negativecount--;
            }else{
                negativecount++;
            }
        }
        return negativecount<=1;
    }
};