class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        if(s.size() == 0)return "";
        bool bold[s.size()];
        memset(bold,false,sizeof(bold));
        
        for(int i=0;i<s.size();i++){
            for(string word : words){
                int len = word.size();
                if(s.substr(i,len) == word){
                    for(int j=i;j<(i+len);j++)bold[j] = true; // mark the nodes which are to be made bold
                }
            }
        }
        string res="";
        for(int start=0;start<s.size();start++){
            if(bold[start]){
                res+="<b>";
                int end = start;
                while(end < s.size() and bold[end] == true)end++;
                res+=s.substr(start,end-start);
                res+="</b>";
                start = end - 1;
            }else{
                res+=s[start];
            }
        }
        return res;
        
        
    }
};