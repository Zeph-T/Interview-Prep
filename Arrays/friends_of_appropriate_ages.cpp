class Solution {
public:
    bool isValid(int x,int y){
        if((y <= 0.5 * x + 7)  or y > x or (y > 100 and x < 100))return false;
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        map<int,int>dict;
        for(int age : ages)dict[age]++;
        int ans = 0;
        
        for(auto ageA : dict){
            for(auto ageB : dict){
                if(!isValid(ageA.first,ageB.first))continue;
                
                int count1 = ageA.second;
                int count2 = ageB.second;
                if(ageA.first == ageB.first)ans += (count1 - 1) * count1;
                else ans += (count1 * count2);
            }
        }
        
        return ans;
    }
};