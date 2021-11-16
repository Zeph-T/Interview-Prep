/*
Rule 1 : the sign should occur at the start, else the character before the sign should be an e, i.e 3e'+'4 else not valid
Rule 2 : if the character is an exponent, their should be a digit already present and their should be only one 'e' inside the string and once it is valid, we reset the digit found to 
false because the number after the exponent is a new number
Rule 3 : if the character is a dot,it should not have appeared before and contain a 'e', as it is not a valid number like 99e2.5 but number like 99.e4 is valid, becuase dot is 
followed by an exponent and not before, and also 99.e is not valid ssince there is not digit after e.
*/



class Solution {
public:
    bool isNumber(string s) {
        bool dfound = false;
        bool efound = false;
        bool dofound = false;
        int i=0;
        int n = s.size();
        while(i<n){
            if(s[i] >= '0' and s[i] <= '9')dfound = true;
            else if(s[i] == '+' or s[i] == '-'){
                if(i>0 and s[i-1] !='e' and s[i-1] !='E' )return false;
            }else if(s[i] == 'e' or s[i] == 'E'){
                if(efound == true or dfound == false)return false;
                efound = true;
                dfound = false;
            }else if(s[i] == '.'){
                if(dofound or efound)return false;
                dofound = true;
            }else{
                return false;
            }
            i++;
        }
        return dfound;
    }
};