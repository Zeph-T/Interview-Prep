class Solution {
public:
    int trailingZeroes(int n) { // the number of zeros is depended on the factor of 5!
        int count = 0;
        if(n  == 0)return 0;
        for(int i=5; n/i >= 1; i = i * 5)count+= n/i;
        return count;
    }
};