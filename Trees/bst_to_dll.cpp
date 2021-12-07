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






/*
Time Complexity : O(N)
Space Complexity : O(1)
*/


class Solution {
public:
    Node* getRightMost(Node* node,Node* curr){
        while(node->right and node->right != curr)node = node->right;
        return node;
    }
    
    
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)return NULL;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* rightMostNode = getRightMost(curr->left,curr);
                if(rightMostNode->right == NULL){
                    rightMostNode->right = curr;
                    curr = curr->left;
                }else{
                    rightMostNode->right = NULL;
                    prev->right = curr;
                    curr->left = prev;
                    prev = curr;
                    curr = curr->right;
                }
            }else{
                prev->right = curr;
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
        Node* newHead = dummy->right;
        newHead->left = prev;
        prev->right = newHead;
        return newHead;
        // return NULL;
    }
};