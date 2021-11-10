/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* newNode = new Node(insertVal);
        if(head == NULL){
            newNode->next = newNode;
            return newNode;
        }
        
        Node* curr = head;
        while(curr->next != head){
            if(curr->val < insertVal and curr->next->val >= insertVal)break;
            if(curr->val > curr->next->val and (curr->next->val >= insertVal or curr->val <= insertVal))break;
            curr = curr->next;
        }
        curr->next = new Node(insertVal,curr->next);
        return head;
    }
};