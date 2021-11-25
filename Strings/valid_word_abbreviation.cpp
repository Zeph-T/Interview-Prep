class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0;
        int j = 0;
        int n1  = word.size();
        int n2 = abbr.size();
        while(i < n1 and j < n2 ){
            if(abbr[j] == '0')return false; 
            if(isdigit(abbr[j])){ // extract the number
                int num = 0;
                while(isdigit(abbr[j])){
                    num = num * 10 + (abbr[j] - '0');
                    j++;
                }
                i+=num; //shift the word pointer num times
            }else{
                if(word[i] == abbr[j]){
                    i++;j++;
                }else{
                    return false;
                }
            }
        }
        if(i == n1 and j == n2)return true;
        return false;
    }
};