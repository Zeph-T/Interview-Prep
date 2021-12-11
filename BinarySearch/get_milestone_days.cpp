vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
  // Write your code here
  int n = revenues.size();
  vector<int>pref(n,0);
  pref[0] = revenues[0];
  int m = milestones.size();
  vector<int>ans(m,0);
  int count = 0;
  for(int i=1;i<n;i++)pref[i] = pref[i-1] + revenues[i];
  for(int target : milestones){
    int start = 0;
    int end = n-1;
    while(start < end){
      int mid = (start + end)/2;
      if(pref[mid] >= target){
        end = mid;
      }else{
        start = mid+1;
      }
    }
    
    ans[count++] = start+1;
    
    
  }
  return ans;
}






