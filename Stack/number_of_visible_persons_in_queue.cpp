class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i] = n - i - 1;
            }else{
                int count = 0;
                while(!st.empty() and heights[st.top()] < heights[i]){
                    count++;
                    st.pop();
                }
                ans[i] = count;
                if(!st.empty())ans[i]++; // if the current height is less than the top element of the stack means this person can see the tallest element in the stack, so we have to add
                // that count
            }
            st.push(i);
        }
        return ans;
    }
    
};
