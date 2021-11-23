/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        
        for(int i=1;i<=n;i++){
            fast = fast->next; // we traverse the fast pointer till it reaches the next node of the target node
        }
        
        while(fast->next){ // now we traverse both of them by one unit when the fast next become null, the slow will point to the node before the target node
            fast = fast->next;
            slow = slow->next;
        }
        
        slow->next = slow->next->next; // update the mappings
        return dummy->next;
        
        
    }
};