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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* curr = head;
        newHead->next = curr;
        ListNode* prev = newHead;
        while(curr and curr->next){
            ListNode* first = curr;
            ListNode* second = curr->next;
            
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            prev = first;
            curr = first->next;
        }
        return newHead->next;
    }
};