class Solution {
public:
    bool isMatch(string str, string pattern) {
        int n = str.size();
        int m = pattern.size();
        bool dp[m +1 ][n+1];
        memset(dp,false,sizeof(dp));
        
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i == 0 and j == 0)dp[i][j] = 1;
                else if(i == 0){
                    dp[i][j] = false;
                }else if(j == 0){
                    char pc = pattern[i-1];
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j];// for null string, the whole string has to be erased, that is pattern = a* and string = "" valid but ab* and string="" not valid
                    }else{
                        dp[i][j] = false;
                    }
                }else{
                    char pc = pattern[i-1];
                    char sc = str[j-1];
                    if(pc == '*'){
                        dp[i][j] = dp[i-2][j]; // let pattern be abc* and string be ab -> in this case c* can be equated to a null character => ab(pattern) = ab(str)
                        char pslc = pattern[i-2]; // abc* => abcc* => abccc* ......
                        if(pslc == '.' or pslc == sc){ // we only have to check if the previous pattern char and string char are valid
                            dp[i][j] = dp[i][j] || dp[i][j-1];
                        }
                    }else if(pc == '.' or sc == pc){
                        dp[i][j] = dp[i-1][j-1]; // we have to consider the previous pattern and string
                    }else{
                           dp[i][j] = false; // false otherwise
                    }
                    
                }
            }
        }
        return dp[m][n];
        
    }
};