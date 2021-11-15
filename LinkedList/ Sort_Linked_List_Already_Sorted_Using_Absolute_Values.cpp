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
    ListNode* sortLinkedList(ListNode* head) {
        ListNode* curr = head;
        while(curr->next){
            if(curr->val > curr->next->val){ // check if the next value is less than the current value
                ListNode* temp = curr->next;
                curr->next = temp->next;
                temp->next = head; // attach the node to the head of the list, since the values coming after if negative will be greater than this node
                head = temp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};