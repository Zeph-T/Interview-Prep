class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int start = 0;
        int end = n-1;
        int ans = INT_MIN;
        while(start < end){
            ans = max(ans , min(height[start]  , height[end]) * (end - start));
            if(height[start] > height[end])end--; // move the end pointer if the heigt at the end pointer is less
            else start++;
        }
        return ans;
    }
};