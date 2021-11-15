/* The knows API is defined for you.
      bool knows(int a, int b); 
      
TC O(N)
SC O(1)      
*/

class Solution {
public:
    bool isCeleb(int cand,int n){
        int res=0;
        for(int i=0;i<n;i++){
            if(i != cand){
                if(knows(i,cand))res++; // check if i person knows cand
                if(knows(cand,i))return false; // if cand knows i, then he wont be a celebrity
            }
        }
        return res == (n-1); // if the cand knows all the other persons
    }
    
    int findCelebrity(int n) {
        int cand = 0;
        for(int i=1;i<n;i++){ 
            if(knows(cand , i)){ // if the cand knows person i, he cannot become the celebrity,so the next possible celeb will be i
                cand = i;
            }
        }
        if(isCeleb(cand,n))return cand;
        else return -1;
    }
};