/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    unordered_map<Node* , NodeCopy* > map;
    
    NodeCopy* copyTree(Node* root){
        if(root == NULL)return NULL;
        
        NodeCopy* newNode = new NodeCopy(root->val);
        map[root] = newNode;
        copyTree(root->left);
        copyTree(root->right);
        return newNode;
    }
        
    
    void connect(Node* node){
        if(node == NULL)return ;
        if(node->left){
            map[node]->left = map[node->left];
        }
        if(node->right){
            map[node]->right = map[node->right];
        }
        if(node->random){
            map[node]->random = map[node->random];
        }
        
        connect(node->left);
        connect(node->right);
        
    }
        
    NodeCopy* copyRandomBinaryTree(Node* root) {
        if(root == NULL)return NULL;
        copyTree(root);
        connect(root);
        return map[root];
        
    }
};