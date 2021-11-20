
/*
TC O(N)
SC O(N)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        stack< pair<char,int> > st;
        for(char ch : chars){
            if(st.empty()){
                st.push({ch , 1});
            }else{
           1     if(st.top().first == ch){
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


/*

TC O(N)
SC O(1)
*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        int n = chars.size();
        int ptr = 0;
        for(int start = 0;start<n;){
            int j = start;
            int count = 1;
            while(j<n-1 and chars[j] == chars[j+1]){
                j++;
                count++;
            }
            
            if(count == 1) chars[ptr++] = chars[start];
            else{
                chars[ptr++] = chars[start];
                string count_string = to_string(count);
                int len = 0;
                while(len < count_string.size()){
                    chars[ptr++] = count_string[len++];
                }
            }
            
            start = j + 1;
        }
        return ptr;
    }
};