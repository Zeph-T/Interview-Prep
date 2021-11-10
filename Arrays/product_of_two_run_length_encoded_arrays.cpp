class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>>ans;
        int i=0 , j=0 ,res1=0 , res2=0 , n1 = encoded1.size(), n2 = encoded2.size();
        while(i < n1 and j < n2){
            if(res1 == 0)res1 = encoded1[i][1];
            if(res2 == 0)res2 = encoded2[j][1];
            int freq = min(res1,res2);
            int product = encoded1[i][0] * encoded2[j][0];
            if(ans.empty() or ans.back()[0] != product)ans.push_back({product,freq});
            else ans.back()[1] += freq;
            
            res1 -= freq;
            res2  -= freq;
            
            if(res1 == 0)i++;
            if(res2 == 0)j++; 
        }
        return ans;
        
    }
};