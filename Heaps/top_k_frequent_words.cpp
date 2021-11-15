typedef pair<int, string> pi;



class comp{
    public:
        bool operator()(pi &a,pi &b){
            if(a.first > b.first)return true; // if the words are of differnet freqeuncy
            else if(a.first == b.first)return a.second < b.second; // return the lexographical order
            else return false;
    }  
};
    

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>mp;
        for(string word: words)mp[word]++;
        priority_queue< pi,vector<pi> ,comp > pq; 
        
        for(auto x : mp){
            pq.push({x.second,x.first});
            if(pq.size() > k)pq.pop();
        }
        
        vector<string>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};