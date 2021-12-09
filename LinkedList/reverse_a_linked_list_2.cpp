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
        if(left == right)return head;
        
        //skip the first left - 1 nodes
        ListNode* current = head;
        ListNode* prev = NULL;
        
        for(int i=0;i<left-1 and current;i++){
            prev = current;
            current = current->next;
        }
        
        ListNode* last = prev;
        ListNode* newEnd = current;
        
        
        //reverse between left and right
        ListNode* next = current->next;
        for(int i=0; current and  i < (right - left + 1) ; i++){
            current->next = prev;
            prev = current;
            current = next;
            if(next != NULL){
                next = next->next;
            }
        }
        
        if(last != NULL){
            last->next = prev;
        }else{
            head = prev;
        }
        
        newEnd->next = current;
        return head;
        
        
    }
};