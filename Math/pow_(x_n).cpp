class Solution {
public:
    double myPow(double x, int n) {
        int negative = false;
        if(n  < 0){
            negative =  true;
            n = abs(n);
        }
        double ans = 1;
        long long nn =  n;
        while(nn != 0){
            if(nn%2 == 0){
                x = x * x;
                nn = nn/2;
            }else{
                ans = ans * x;
                nn--;
            }
        }
        return (negative) ? (double)(1)/(double)(ans) : ans;
    }
};