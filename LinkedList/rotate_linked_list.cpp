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
    int lengthOfLinkedList(ListNode* head){
        int count =0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)return NULL;
        if(k == 0 or head->next == NULL)return head;
        int n = lengthOfLinkedList(head);
        k = k%n;
        
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0;i<k and fast!=NULL;i++){
            fast = fast->next;
        }
        
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        fast->next = head;
        head = slow->next;
        slow->next = NULL;
        return head;
        
    }
};