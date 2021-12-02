/*
Approach 1 : Uses monotonic stack to keep track of max so far
Time Complexity : O(N)
Space Complexity: O(N)
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int>st;
        int n = temp.size();
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                ans[i] = 0;
            }else{
                while(!st.empty() and temp[st.top()] <= temp[i])st.pop();
                if(st.size() == 0)ans[i] = 0;
                else ans[i] = st.top() - i;
            }
            st.push(i);
        }
        return ans;
    }
};



/*
Approach 2 : This doesnot take up additional space but it does increase the number of iterations i.e to 
Time Complexity : O(2*N)
Space Complexity : O(1)

*/


class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n = temp.size();
        vector<int>ans(n,0);
        int hottest_till_now = 0;
        for(int i=n-1;i>=0;i--){
            int current = temp[i];
            if(current >= hottest_till_now){
                hottest_till_now = current;
                continue;
            }
            
            int days = 1;
            while(temp[i + days ]<= current){
                days += ans[i + days];
            }
            ans[i] = days;
        }
        
        return ans;
        
    }
};