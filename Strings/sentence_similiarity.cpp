class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        int n1 = sentence1.size();
        int n2 = sentence2.size();
        if(n1 != n2)return false;
        
        unordered_set<string>st;
        for(auto pair : similarPairs){
            st.insert(pair[0] + "," + pair[1]);
        }
        
        for(int i=0;i<n1;i++){
            string s1 = sentence1[i];
            string s2 = sentence2[i];
            
            if(s1 == s2 or st.find(s1+","+s2) != st.end() or st.find(s2+","+s1)!= st.end())continue;
            else return false;
        }
        
        return true;
        
        
        
    }
};