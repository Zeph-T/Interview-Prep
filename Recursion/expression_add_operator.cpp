/*
The previous variable is only used incase of multiplication symbol as it takes
higher precendence than + and -


Time Complexity : O(N * 4 ^ N)
Space Complexity : O(N)
*/


class Solution {
public:
    vector<string>ans;
    
    
    void backtrack(string num , int target, int index , string path ,long res  , long prev){
        if(index == num.size()){ // base case
            if(res == target){ // result keeps track of the sum acquinted till now
                ans.push_back(path); 
            }
            return ;
        }
        
        int n = num.size();
        long number = 0;
        string substring = "";
        for(int i= index; i < n ;i++ ){
            substring += num[i];
            number = number * 10 + (num[i] - '0');
            if(substring.size() > 1 and substring[0] == '0')break; // if we find a sustring with leading zero and size greater than 1, not valid
            if(index == 0){
                backtrack(num , target , i+ 1,substring , number , number); // first string
            }else{
                backtrack(num , target , i + 1 , path + '+'  + substring , res + number  , number ); // the previous becomes the current number
                backtrack(num , target , i + 1 , path + '-'  + substring , res - number , - number); // the previous becomes the negative of current number 
                backtrack(num , target , i + 1 , path + '*' + substring , (res  - prev ) + (prev * number) , prev * number); // here we have to subtract the prev from the result bevcause we would be
                // considering the current digit for more precedence.
            }
        }
        
        
    }
    
    vector<string> addOperators(string num, int target) {
        backtrack(num , target , 0 , "" , 0 , 0 );
        return ans;
    }
};