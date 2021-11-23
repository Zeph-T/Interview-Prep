class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        int len  = flower.size();
        int count = 0;
        for(int i=0;i<len;i++){
            if(flower[i] == 0){
                if((i == 0 or flower[i-1] == 0) and  (i == len - 1 or flower[i+1] == 0)){
                    count++;
                    flower[i] = 1;
                }
            }
            if(count >=n )return true;
        }
        return count>=n;
    }
};