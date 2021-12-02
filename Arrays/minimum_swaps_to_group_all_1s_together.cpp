class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0;
        int n = data.size();
        for(int bit : data){
            if(bit == 1)ones++;
        }
        if(ones == 0)return 0;
        int i=0;
        int ans = INT_MAX;
        int number_of_ones = 0;
        for(int j=0;j<n;j++){
            if(data[j] == 1)number_of_ones++;
            
            if(j - i + 1 == ones){
                ans = min(ans ,ones - number_of_ones);
                if(data[i] == 1)number_of_ones--;
                i++;
            }
        }
        return ans;
        
        
    }
};