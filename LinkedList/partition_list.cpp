/**
 make two seperate linkedlists which consists
 of less than x nodes and greater than or equal to nodes
 * 
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* before_head = new ListNode(-1);
        ListNode* before = before_head;
        ListNode* after_head = new ListNode(-1);
        ListNode* after = after_head;
        
        ListNode* curr = head;
        while(curr){
            if(curr->val < x){
                before->next = curr;
                before = before->next;
            }else{
                after->next = curr;
                after = after->next;
            }
            curr = curr->next;
        }
        
        
        after->next = NULL;
        before->next = after_head->next;
        return before_head->next;
        
    }
};