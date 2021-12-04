class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        map<int,int>dict;
        for(int num : arr)dict[num]++;
        priority_queue<int,vector<int> , greater<int>> minHeap;
        
        for(auto x : dict){
            minHeap.push(x.second);
        }
        
        int total_uniques = dict.size();
        int removed = 0;
        while(k > 0 and !minHeap.empty()){
            int top = minHeap.top();
            top--;
            minHeap.pop();
            k--;
            if(top == 0){
                removed++;
            }
            else minHeap.push(top);
        }
        
        return total_uniques - removed;
        
    }
};