/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* newNode;
        Node* root = head;
        while(root){
            Node* temp = root->next;
            newNode = new Node(root->val);
            root->next = newNode;
            newNode->next = temp;
            root = temp;
        }
        root = head;
        while(root){
            if(root->random)
                root->next->random = root->random->next;
            else
                root->next->random = NULL;
            root = root->next->next;
        }
        
        root = head;
        Node* sHead = new Node(0); // new Head
        Node* copy = sHead;
        while(root){
            Node* temp = root->next->next; // 
            copy->next = root->next;
            root->next = temp;
            copy = copy->next;
            root = root->next;
        }
        return sHead->next;
    }
};