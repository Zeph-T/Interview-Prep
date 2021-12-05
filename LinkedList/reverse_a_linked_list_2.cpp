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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL)return NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        
        while(left > 1){
            prev = curr;
            curr = curr->next;
            left--;
            right--;
        }
        
        ListNode* connection = prev; // get the prev node of the left val to connect it to the right node after revrersing the segment
        ListNode* tail = curr; // this is used to connect to the right val after reversing
        
        while(right > 0){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            right--;
        }
        
        if(connection){
            connection->next = prev;
        }else{
            head = prev;
        }
        
        tail->next = curr;
        
        return head;
        
    }
};