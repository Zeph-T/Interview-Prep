class Solution {
public:
    
    bool isVowel(char ch){
        if(ch == 'a' or ch == 'e' or ch == 'i' or ch == 'o' or ch== 'u' or ch == 'A' or ch == 'E' or ch == 'I' or ch == 'O' or ch == 'U')return true;
        else return false;
    }
    
    
    string toGoatLatin(string sentence) {
        string res="";
        string temp="";
        int index = 1;
        for(char ch : sentence){
            if(ch == ' '){
                if(temp.size() > 0){
                    if(!isVowel(temp[0])){
                        char temp_char = temp[0];
                        temp = temp.substr(1);
                        temp = temp + temp_char;
                    }
                    temp = temp + "ma";
                    for(int i=0;i<index;i++)temp+="a";
                    res = res + temp + " ";
                    temp ="";
                    index++;
                }
            }else{
                temp += ch;
            }
        }
        
        if(!isVowel(temp[0])){
            char temp_char = temp[0];
            temp = temp.substr(1);
            temp = temp + temp_char;
        }
        temp = temp + "ma";
        for(int i=0;i<index;i++)temp+="a";
        res = res + temp;

        return res;
        
        
    }
};