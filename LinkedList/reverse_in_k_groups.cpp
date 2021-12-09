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
    int length(ListNode* head){
        int count = 0;
        while(head){
            head = head->next;
            count++;
        }
        return count;
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL or k == 1)return head;
        ListNode* current = head ;
        ListNode* prev = NULL;
        int count = length(head);
        while(current and count >= k){
            ListNode* last = prev; // the previous node for the present k groud
            ListNode* newEnd = current; // the upcoming end after reversing
            for(int i=0;current and i<k ; i++){
                ListNode* nextNode = current->next; // reverse all the k groups
                current->next = prev;
                prev = current;
                current = nextNode;
            } 
            if(last){ 
                last->next = prev; // attach the next of the last node before the k group
            }else{ // to the previous
                head = prev; // for the initial case
            }
            count-=k;
            newEnd->next = current; // the newEnd should point to current which would be the start for the next k group
            prev = newEnd;// thhis would be the last node for the previous k grouop for next iteration
        }

        return head;
        
        
    }
};