class Solution {
public:
    
    vector<int>merge(vector<int>a,vector<int>b){
        int n1 = a.size();
        int n2 = b.size();
        vector<int>ans;
        int i=0,j=0;
        while(i < n1 and j < n2){
            if(a[i] == b[j]){
                ans.push_back(a[i]);
                i++;
                j++;
            }else if(a[i] > b[j])j++;
            else i++;
        }
        return ans;
    }
    
    
    
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        vector<vector<int>>merged;
        while(arrays.size() != 1){
            vector<int>v1 = arrays.back();
            arrays.pop_back();
            vector<int>v2 = arrays.back();
            arrays.pop_back();
            arrays.push_back(merge(v1,v2));
        }
        return arrays.back();
    }
};