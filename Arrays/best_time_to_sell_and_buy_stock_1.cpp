class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;  // keep track ofthe min price iterated till now
        int profit = 0;
        for(int price : prices){
            minPrice = min(minPrice,price); // update the min price till now
            profit = max(profit,price - minPrice); // update the profit
        }
        return profit;
    }
};