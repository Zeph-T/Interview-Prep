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
    
    ListNode* mergeLists(ListNode* head1,ListNode* head2){
        ListNode* curr = new ListNode(0);
        ListNode* head = curr;
        while(head1 and head2){
            ListNode* newNode;
            if(head1->val > head2->val){
                head->next = head2;
                head2 = head2->next;
            }else{
                head->next = head1;
                head1 = head1->next;
            }            
            head = head->next;
        }
        
        while(head1){
            head->next = head1;
            head1 = head1->next;
            head = head->next;
        }
        
        while(head2){
            head->next = head2;
            head2 = head2->next;
            head = head->next;
        }
        
        return curr->next;
        
    }
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return NULL;
        while(lists.size() > 1){
            ListNode* head1 = lists.back();
            lists.pop_back();
            ListNode* head2 = lists.back();
            lists.pop_back();
            
            
            ListNode* newNode = mergeLists(head1,head2);
            lists.push_back(newNode);
            
        }
        return lists.back();
    }
};