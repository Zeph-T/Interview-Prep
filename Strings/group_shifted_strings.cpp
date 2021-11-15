class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string> >mp;
        for(string str : strings){
            string key = "";
            int len = str.size(); // create a key to store for the shift
            for(int i=1;i<len;i++){
                int distance = str[i] - str[i-1]; // character shift between two chars is seperated by #
                if(distance < 0)distance += 26;
                key += to_string(distance) + "#"; 
                
            }
            // cout<<str<<" "<<key<<endl;
            mp[key].push_back(str);
        }
        vector<vector<string>>ans;
        for(auto x: mp){
            ans.push_back({x.second.begin(),x.second.end()});
        }
        return ans;
    }
};