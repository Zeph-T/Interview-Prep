class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        string source="0000";
        queue<string>q;
        q.push(source);
        int distance = 0;
        unordered_set<string>visited;
        for(string s : deadends){
            visited.insert(s);
        }
        
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                string top = q.front();
                q.pop();
                if(visited.find(top) != visited.end())continue;
                visited.insert(top);
                if(top == target)return distance;
                
                for(int pos = 0;pos < top.size();pos++){
                    string temp1 = top;
                    string temp2 = top;
                    
                    char ch = temp1[pos];
                    if(ch == '9')temp1[pos] = '0';  //move forward
                    else temp1[pos] = ch + 1;

                    ch = temp2[pos];
                    if(ch == '0')temp2[pos] = '9'; // move backward
                    else temp2[pos] = ch - 1;
                    
                    if(visited.find(temp1) == visited.end()){
                        q.push(temp1);
                    }
                    if(visited.find(temp2) == visited.end()){
                        q.push(temp2);
                    }
                    
                }
            }
            distance++;
        }
        return -1; 
    }
};