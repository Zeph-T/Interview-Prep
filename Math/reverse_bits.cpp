class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int bit = 31;bit>=0;bit--){
            result += (n & 1) << bit;
            n = n >> 1;
        }
        return result;
    }
};