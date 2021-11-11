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

    void maxRightHelper(vector<int>&arr,vector<int>&heights){
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
            int side = min(heights[i] ,maxRight[i] - maxLeft[i] - 1 );
            ans = max(ans , side* side);
        }
        return ans;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0)return 0;
        int m = matrix[0].size();
        int ans = 0;
        vector<int>temp(m,0);
        for(int i=0;i<n;i++){ // consider each row as a histgoram
            for(int j=-0;j<m;j++){
                matrix[i][j] != '0' ? temp[j] += 1: temp[j] = 0;
            }
            ans = max(ans , largestRectangleArea(temp));
        }
        return ans;
    }
};