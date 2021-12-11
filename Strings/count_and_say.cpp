class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)return "1";
        if(n == 2)return "11";
        string res="1";
        for(int i=0;i<n-1;i++){
            char ch = res[0];
            int count =1;
            string temp = "";
            for(int j=1;j<res.size();j++){
                if(ch != res[j]){
                    temp += to_string(count);
                    temp += ch;
                    count = 0;
                    ch = res[j];
                }
                count++;
            }
            temp += to_string(count);
            temp += ch;
            res = temp;
        }
        return res;
        
        
    }
};