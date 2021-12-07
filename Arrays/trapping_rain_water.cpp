/*
Time Complexity : O(N)
Space Complexity : O(N)
Using prefixMax Arrays

*/

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxLeft[n];
        int maxRight[n];
        maxLeft[0] = 0;
        for(int i=1;i<n;i++)maxLeft[i] = max(maxLeft[i-1],height[i-1]);
        maxRight[n-1] =  0;
        for(int i=n-2;i>=0;i--)maxRight[i] = max(maxRight[i+1],height[i+1]);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(0,min(maxLeft[i],maxRight[i]) - height[i]);
        }
        return ans;
    }
};




/*
Time Complexity : O(N)
Space Complexity : O(1)
Intuition : Instead of keeping track of the maxLeft and maxRight,
we can use two pointers at both end and get the amount of 
water the least out of two heights can hold up
We only move pointers when we will know there is some pillar with
height greater than the current in the opposite direction
*/



class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int right_max = 0;
        int left_max = 0;
        int ans = 0;
        while(i < j){
            if(height[i] < height[j]){
                height[i] >= left_max ? left_max = height[i] : ans += (left_max - height[i]);
                i++;
            }else{
                height[j] >= right_max ? right_max = height[j] : ans += (right_max - height[j]);
                j--;
            }
        }
        return ans;
    }
};