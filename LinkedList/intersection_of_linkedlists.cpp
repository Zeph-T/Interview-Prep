/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
         ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA != pB) {
            pA = pA == NULL ? headB : pA->next;
            pB = pB == NULL ? headA : pB->next;
        }
        return pA;
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        ListNode* a = head1;
        ListNode* b = head2;
        while(a != b){
            a = a == NULL? head2 : a->next;
            b = b == NULL ? head1 : b->next;
        }
        return a;
    }
};