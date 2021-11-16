class Solution {
public:
    int compress(vector<char>& chars) {
        stack< pair<char,int> > st;
        for(char ch : chars){
            if(st.empty()){
                st.push({ch , 1});
            }else{
                if(st.top().first == ch){
                    auto top = st.top();
                    st.pop();
                    st.push({top.first , top.second + 1});
                }else{
                    st.push({ch , 1});
                }
            }
        }
        int ans = 0;
        int pointer = 0;
        int size = 0;
        stack<pair<char,int>>newStack;
        while(!st.empty()){
            newStack.push(st.top());
            st.pop();
        }
        
        
        while(!newStack.empty()){
            auto element = newStack.top();
            newStack.pop();
            int freq = element.second;
            char ch = element.first;
            chars[pointer++] = ch;
            ans++;
            int temp = freq;
            
            if(freq > 1){
                string res="";
                while(freq > 0){
                    ans++;
                    // cout<<ans<<" ";
                    res += (freq%10 + '0');
                    freq = freq/10;
                }
                int i=res.size() - 1;
                while( i >= 0){
                    chars[pointer++] = res[i];
                    i--;
                }
            }
        }
        return ans;
    }
};