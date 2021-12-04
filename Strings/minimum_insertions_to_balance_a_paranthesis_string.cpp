class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        int count = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '(')count+=2; // since every left paranthesis is balanced with two closing braces
            else{
                if(count > 0){ // there are opening brackets already before
                    if((i + 1) < n and s[i+1] == ')'){  // balanced expression
                        count-=2; // the closing and opening bracket negate each other -> ()) -> cleans out
                        i++; // we used this character
                    }else{
                        count-=2; // we have to add one opening closing character to balance the before string 
                        ans++; // example ()( -> we will add one closing bracket -> "())"(
                    }
                }else{ // there are no opening brackets before, so we have to add one opening bracket for sure
                            // if the next character is also closing bracket,  we need to add one else add two
                    if( ( i + 1) < n and s[i+1] == ')'){
                        ans++; 
                        i++;
                    }else{
                        ans += 2;
                    }
                }
            }
        }
        return ans + count;
    }
};