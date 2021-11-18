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
            if(curr->val < insertVal and curr->next->val >= insertVal)break; // if the new value lies between node and node->next value
            if(curr->val > curr->next->val and (curr->next->val >= insertVal or curr->val <= insertVal))break; // conside the case where curr->val = 6 and curr->next->val = 4 then the value which can be inserted in between can be the maximum the curr->val or minuimum of curr->next->val i,e we can add nodes with value > =6 or less than 4
            curr = curr->next;
        }
        curr->next = new Node(insertVal,curr->next);
        return head;
    }
};