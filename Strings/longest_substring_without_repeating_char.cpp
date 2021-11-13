class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0,j=0;
        unordered_map<char,int>mp; // store the last occurence index of the char
        while(j<s.size()){
            if(mp.find(s[j]) != mp.end()){ // if the char was laready present in the window,shrink them window by moving the start to the last occurence.
                i = mp[s[j]];
                mp[s[j]] = j;
            }else{
                mp[s[j]] = j;
            }
            ans = max(ans , j-i+1);
            j++;
        }
        return ans-1;
        
    }
};