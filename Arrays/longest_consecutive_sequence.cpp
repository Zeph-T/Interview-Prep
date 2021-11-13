class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(),nums.end());
        int streak = 0;
        // for(int n : s)cout<<n<<" ";
        for(int num : s){
            if(s.find(num-1) == s.end()){ // check if the element is the start point a sequence
                int current = num;
                int streak_current = 1;
                while(s.find(current+1) != s.end()){ // get the longest sequence possible 
                    current++;
                    streak_current++;
                }
                streak = max(streak_current,streak); // update the count
            }
        }
        return streak;
    }
};