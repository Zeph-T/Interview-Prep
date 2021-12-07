class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        if(head == NULL)return 0;
        ListNode* curr = head;
        while(curr){
            ans = ans * 2  + curr->val;
            curr = curr->next;
        }
        return ans;
        
    }
};