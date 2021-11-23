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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == NULL)return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next and fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* second_half = reverseList(slow->next); //reverse the second half of the linkedlist and check if the values are same.
        
        while(second_half){
            if(second_half->val != head->val)return false;
            head = head->next;
            second_half = second_half->next;
        }
        return true;
        
    }
};