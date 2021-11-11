class Solution {
public:
    int titleToNumber(string columnTitle) {
        int number = 0;
        int n = columnTitle.size();
        int exp = 0;
        for(char ch : columnTitle){
            number += (ch - 'A' + 1) * pow( 26 , --n);
        }
        return number;
    }
};