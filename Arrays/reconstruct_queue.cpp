class Solution {
public:
    static bool comp1(vector<int>&a,vector<int>&b){
        if(a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    

    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),comp1);
        int count = 0;
        int n = people.size();
        vector<vector<int>>ans(n,vector<int>(2,-1));
        for(int i=0;i<n;i++){ // at eaach iteration we assign the position of the ith person in the queue
            int count = people[i][1];
            for(int j=0;j<n;j++){ // searching for the position of the ith member
                if(ans[j][0] == -1){ // -1 means not allocated yet, and the number of members greater than the person height has reached K.
                    if(count == 0){
                        ans[j][0] = people[i][0];
                        ans[j][1] = people[i][1];
                        break;   
                    }else{
                        count--; // meaning the place would be occupied by the person whose height is greater than or equal to the current person, so we 
                        //reduce the count
                    }
                }else if(ans[j][0] >= people[i][0]){
                     count--; // if we already assigned the person in that position and his height is greater than or equal to the current person,
                        // we reduce the count
                }
            }
        }
        return ans;
    }
};