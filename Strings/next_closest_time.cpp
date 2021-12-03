class Solution {
public:
    string nextClosestTime(string time) {
        int minutes = stoi(time.substr(0,2)) * 60 + stoi(time.substr(3,2)) ;
        unordered_set<int>digits;
        digits.insert(time[0] - '0');
        digits.insert(time[1] - '0');
        digits.insert(time[3] - '0');
        digits.insert(time[4] - '0');
        
        
        while(true){
            minutes = (minutes + 1) % (24 * 60);
            vector<int>nextTime = {minutes/600 ,(minutes/60)%10 , (minutes%60)/10 , (minutes%60)%10};
            bool isValid = true;
            for(int digit : nextTime){
                if(digits.count(digit) == 0){
                    isValid = false;
                    break;
                }
            }
            
            if(isValid){
                return to_string(nextTime[0]) + to_string(nextTime[1]) + ":" + to_string(nextTime[2]) + to_string(nextTime[3]);
            }
        }
        return "";
        
    }
};