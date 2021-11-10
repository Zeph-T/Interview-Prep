class Solution {
public:
    string removeDuplicates(string s, int k) {
        int count = 0;
        stack<pair<int,int>>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(st.empty() || s[i] != st.top().second)st.push({1,s[i]});
            else if(++st.top().first == k)st.pop();
        } 
        string res="";
        while(!st.empty()){
            int len = st.top().first;
            char ch = st.top().second;
            st.pop();
            for(int i=0;i<len;i++)res+=ch;
        }
        reverse(res.begin(),res.end());
        return res; 
    }
};