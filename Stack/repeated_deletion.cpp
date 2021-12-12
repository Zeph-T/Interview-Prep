string solve(string s) {
    string ans = "";
    for(int i=0;i<s.size() ; i++){
        while(!ans.empty() and i < s.size() and ans.back() == s[i]){
            while(i < s.size() and s[i] == ans.back())i++;
            ans.pop_back();
        }
        if(i < s.size() )ans.push_back(s[i]);
    }
    return ans;
}