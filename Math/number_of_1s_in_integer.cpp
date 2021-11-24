class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0 ;
        while(n != 0){
            count++;
            n = n&(n-1); // since n-1 flips the least significant '1' in n. and the AND of n and n-1 only makes the LSB as 0 and rest remains the same

        }
        return count;
    }
};