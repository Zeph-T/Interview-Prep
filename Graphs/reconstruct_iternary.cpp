class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans;
        unordered_map<string,multiset<string>>g;
        
        for(auto ticket: tickets){
            g[ticket[0]].insert(ticket[1]);
        }
        
        stack<string>st;
        st.push("JFK");
        while(!st.empty()){
            string top = st.top();
            
            if(g[top].size() == 0){
                ans.push_back(top);
                st.pop();
            }else{
                auto destination = g[top].begin();
                st.push(*destination);
                g[top].erase(destination);
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};