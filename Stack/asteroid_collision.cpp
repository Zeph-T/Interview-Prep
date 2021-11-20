class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        bool include = false;
        for(int asteroid : asteroids){
            include = true;
            while(!st.empty() and st.top() > 0 and asteroid < 0){
                if(st.top() > abs(asteroid)){
                    include = false;
                    break;
                }else if(st.top() < abs(asteroid))st.pop();
                else if(st.top() == abs(asteroid)){
                    include = false;
                    st.pop();
                    break;
                }
            }
            if(include)st.push(asteroid);
        }
        
        int len = st.size(); 
        vector<int>ans(len);
        while(!st.empty()){
            ans[--len] = st.top();
            st.pop();
        }
        return ans;
    }
};