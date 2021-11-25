class Solution {
public:
    vector<string>ans;
    unordered_map<int,vector<char>>phone;

    void recur(string curr,int pos,string digits){
        if(pos == digits.size()){
            ans.push_back(curr);
            return ;
        }
        if(pos > digits.size())return ;
        
        for(char ch : phone[digits[pos]]){
            curr += ch;
            recur(curr,pos+1,digits);
            curr.pop_back();
        }
        return ;
    }
    
    
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)return ans;
        phone['2'] = {'a','b','c'};
        phone['3'] = {'d','e','f'};
        phone['4'] = {'g','h' , 'i'};
        phone['5'] = {'j' , 'k' , 'l'};
        phone['6'] = {'m','n','o'};
        phone['7'] = {'p','q','r','s'};
        phone['8'] = {'t','u','v'};
        phone['9'] = {'w','x','y' , 'z'};
        recur("",0,digits);
        return ans;
    }
};