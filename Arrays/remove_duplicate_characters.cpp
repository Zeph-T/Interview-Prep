/*
Store the frequency of the characters,while iterating, if the stack is empty push the element to the stack, else check the top element with the current character and ascii value of the
current char  is less than the top element of the stack as well as its frequency is greater than 0 means that the character occurs after the position as well.
return the string with reversed.


Time Complexity : O(N)
Space Complexity : O(1)
*/






class Solution {
public:
    string removeDuplicateLetters(string s) {
        int freq[26]; 
        memset(freq,0,sizeof(freq));
        for(char ch : s){
            freq[ch - 'a']++;
        }
        int n = s.size();
        stack<char>st;
        bool visited[26];
        memset(visited,false,sizeof(visited));
        int i=0;
        for(int i=0;i<n;i++){
            char ch = s[i];
            freq[ch - 'a']--;
            if(visited[ch - 'a'])continue;
            while(st.size() > 0 and ch < st.top() and freq[st.top() - 'a'] > 0){
                visited[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(ch);
            visited[ch - 'a'] = true;   
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};