class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        unordered_map<char,int>map;
        int n = s.size();
        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;
        num += map[s[n-1]];
        for(int i=n-2;i>=0;i--){
            if(map[s[i]] < map[s[i+1]])num -= map[s[i]]; // check adjacent character like IV , where the right char has more precedence than the left char so we substract here
                                                            // here we add
            else num += map[s[i]];
        }
        return num;
    }
};