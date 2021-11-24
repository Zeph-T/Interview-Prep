

/*
Time Complexity : O(N)
Space Complexity : O(N) since we are creating new node each time
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* root = head;
        ListNode* head1 = l1;
        ListNode* head2 = l2;
        while(head2!=NULL and head1!=NULL){
            if(head1->val > head2->val){
                root->next = new ListNode(head2->val);
                head2 = head2->next;
            }else{
                root->next = new ListNode(head1->val);
                head1 = head1->next;
            }
            root = root->next;
        }
        while(head1){
            root->next = new ListNode(head1->val);
            root = root->next;
            head1 = head1->next;
        }
        while(head2){
            root->next = new ListNode(head2->val);
            root = root->next;
            head2 = head2->next;
        }
        return head->next;
    }
};



/**
Time Complexity : O(N)
Space COmplexity : O(1)
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while(l1 and l2){
            if(l1->val <= l2->val){
                prev->next = l1;
                l1 = l1->next;
            }else{
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }
        prev->next = l1 == NULL ? l2 : l1;
        return dummy->next;
    }
};