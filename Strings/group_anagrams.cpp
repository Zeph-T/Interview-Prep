/*
sort the string, since the anagrams will have the same string,and append the string, to the map with key as the sorted string
time complexity : O(NKLogK)
Space : O(NK)
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str : strs){
            string temp = str;
            sort(temp.begin(),temp.end());
            mp[temp].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto x : mp){
            vector<string>st;
            for(string s :x.second){
                st.push_back(s);
            }
            ans.push_back(st);
        }
        return ans;
    }
};



/*
store the character count as the key and the values as the string
Time COmplexity : O(NK)
Space COmplexity  : O(NK)
*/

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = collections.defaultdict(list)
        for str in strs:
            count = [0] * 26
            for ch in str:
                count[ord(ch) - ord('a')]+=1
            ans[tuple(count)].append(str)
        return ans.values()
        