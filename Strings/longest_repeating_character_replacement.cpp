    int characterReplacement(string s, int k) {
        int count[128];
        memset(count,0,sizeof(count));
        int max_count = 0;
        int len = 0;
        int i=0;
        int n = s.size();
        for(int j=0;j<n;j++){
            count[s[j]]++;
            max_count = max(max_count , count[s[j]]);
            
            while(j - i + 1 - max_count > k){ // the window len will be j - i + 1 and the max_count will be the character with the max frequency
                count[s[i]]--;
                max_count = max(max_count , count[s[i]]); // if we reduce the window size there  might be case when the max_count is removed, so we have to update it as well
                i++;
            }
            
            len = max(len , j -i + 1);
        }
        return len;
    }