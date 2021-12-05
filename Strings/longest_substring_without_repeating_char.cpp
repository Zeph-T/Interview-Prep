int longestSubstringWithoutRepeat(string s) {
	unordered_map<char,int>map;
	int ans = 0;
	int i = 0;
	int n = s.size();
	for(int j=0;j<n;){
		if(map[s[j]] == 0){
			ans = max(ans , j - i + 1);
			map[s[j]]++;
			j++;
		}else{
			map[s[i]]--;
			i++;
		}
	}
	return ans;
	
	
    // add your logic here
}