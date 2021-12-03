class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<int,int>map;
        for(char ch : s)map[ch]++;
        priority_queue<pair<int,char>>pq;
        for(auto x : map){
            pq.push({x.second,x.first});
        }
        string res="";
        while(pq.size() > 1){
            char ch1 = pq.top().second;
            int count1 = pq.top().first;
            pq.pop();
            char ch2 = pq.top().second;
            int count2 = pq.top().first;
            pq.pop();
            res = res + ch1 + ch2;
            count1--;count2--;
            if(count1 > 0)
                pq.push({count1,ch1});
            if(count2 > 0)
                pq.push({count2,ch2});
        }
        
        if(pq.size() > 0){
            char lastChar = pq.top().second;
            int count = pq.top().first;
            pq.pop();
            if(count == 1)res+=lastChar;
            else return "";
        }
        return res;
        
        
    }
};