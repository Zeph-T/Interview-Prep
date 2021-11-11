class Solution {
public:
    
    void maxLeftHelper(vector<int>&arr,vector<int>heights){
        stack<int>st;
        int n = heights.size();
        for(int i=0;i<n;i++){
            if(st.size() == 0)arr[i] = -1;
            else{
                while(!st.empty() and heights[st.top()] >= heights[i])st.pop();
                if(st.size() == 0)arr[i] = -1;
                else arr[i] = st.top();
            }
            st.push(i);
        }
    }
    
    void maxRightHelper(vector<int>&arr,vector<int>&heights){ // next smaller element to the right
        stack<int>st; 
        int n = heights.size();
        for(int i=n-1;i>=0;i--){
            if(st.size() == 0)arr[i] = n;
            else{
                while(!st.empty() and heights[st.top()] >= heights[i])st.pop();
                if(st.size() == 0)arr[i] = n;
                else arr[i] = st.top();
            }
            st.push(i);
        }
    }
    

    
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>maxLeft(n,0); 
        vector<int>maxRight(n,0);
    
        maxLeftHelper(maxLeft,heights);
        maxRightHelper(maxRight,heights);
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans , heights[i] * (maxRight[i] - maxLeft[i] - 1));
        }
        return ans;
    }
};