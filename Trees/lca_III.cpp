/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    
    Node* find(Node* root,Node* p,Node* q){
        if(root == NULL or root == q or root == p)return root;
        Node* l = find(root->left,p,q);
        Node* r = find(root->right,p,q);
        if(l == NULL)return r;
        else if(r == NULL)return l;
        else return root;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node* root;
        Node* temp = p;
        while(temp->parent != NULL){
            temp = temp->parent;
        }
        root = temp;
        return find(root,p,q);
    }
};