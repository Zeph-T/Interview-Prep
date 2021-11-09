class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int lastIndex[10];
        memset(lastIndex,-1,sizeof(lastIndex));
        for(int i=0;i<s.size();i++){
            int digit = s[i] - '0';
            lastIndex[digit] = i;
        }
        int n = s.size();
        bool flag = true;
        for(int i=0;i<n;i++){
            int presentDigit = s[i] - '0';
            for(int j = 9;j>presentDigit;j--){
                if(lastIndex[j] > i){
                    char temp = s[lastIndex[j]];
                    s[lastIndex[j]] = s[i];
                    s[i] = temp;
                    flag=  false;
                    break;
                }
            }
            if(flag == false)break;
        }
        return stoi(s);
    }
};