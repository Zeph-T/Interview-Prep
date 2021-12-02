class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int , vector<int> , greater<int>> minheap;
        for(int stick : sticks){
            minheap.push(stick);
        }
        int ans  = 0;
        while(minheap.size() != 1){
            int top1 = minheap.top();
            minheap.pop();
            int top2 = minheap.top();
            minheap.pop();
            ans += (top1 + top2);
            minheap.push(top1 + top2);
        }
        
        
        return ans;
        
        
        
    }
};