/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* prev = NULL;
    
    void dfs(Node* node){
        if(node == NULL)return ;
        
        dfs(node->left);
        
        prev->right = node;
        node->left = prev;
        prev = node;
        dfs(node->right);
    }
    
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)return NULL;
        Node* dummy = new Node(-1);
        prev = dummy;
        dfs(root);
        Node* head = dummy->right;
        head->left = prev;
        prev->right = head;
        return head;
    }
};