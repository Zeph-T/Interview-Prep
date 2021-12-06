class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDistance = 0;
        int n = colors.size();
        int first_color = colors[0];
        
        for(int i = n-1;i>=0;i--){
            if(colors[i] != first_color){
                maxDistance = max(maxDistance , i);
            }
        }
        int last_color = colors[n-1];
        for(int i=0;i<n;i++){
            if(colors[i] != last_color){
                maxDistance = max(maxDistance , n - i - 1);
            }
        }
        
        return maxDistance;
        
        
    }
};