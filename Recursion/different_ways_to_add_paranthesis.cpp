class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int>ans;
        int n = exp.size();
        for(int i=0;i<n;i++){
            char ch = exp[i];
            
            
            if(ch == '+' or ch == '-' or ch == '*'){
                auto firstHalf = diffWaysToCompute(exp.substr(0,i));
                auto secondHalf = diffWaysToCompute(exp.substr(i+1));

                for(int a : firstHalf){
                    for(int b : secondHalf){
                        switch(ch){
                            case '+':
                                ans.push_back(a + b);
                                break;
                            case '-':
                                ans.push_back(a - b);
                                break;
                            case '*' : 
                                ans.push_back(a * b);
                                break;
                        }
                    }
                }   
            }
        }
            
        if(ans.size() == 0 and exp.size() > 0)ans.push_back(stoi(exp));
        return ans;
    }
};