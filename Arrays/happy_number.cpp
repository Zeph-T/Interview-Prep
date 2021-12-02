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
        unordered_set<int>visited;
        while(n!=1 and visited.count(n) == 0){
            visited.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};