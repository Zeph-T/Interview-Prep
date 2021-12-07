class Solution {
public:
    string simplifyPath(string path) {
        vector<string>st;
        string current = "";
        path += "/";
        for(char ch : path){
            if(ch == '/'){
                if(current==".."){
                    if(st.size())st.pop_back();
                }else if(current.size()>0 and current!="."){
                    st.push_back(current);
                }
                current = "";
            }else{
                current += ch;
            }
        }
        
        string ans="";
        for(string str : st){
            ans =  ans + "/" + str;
        }
        return ans.size() == 0 ? "/" : ans;
    }
};