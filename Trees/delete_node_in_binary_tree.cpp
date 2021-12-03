/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int maxFromLeft(TreeNode* root){
        if(root->right != NULL)return maxFromLeft(root->right);
        else return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* root, int data) {
        if(root == NULL)return NULL;
        if(data > root->val){
            root->right = deleteNode(root->right,data);
        }else if(data < root->val){
            root->left = deleteNode(root->left,data);
        }else{
            if(root->left and root->right){ // if both left and right subtrees are present. we can replace the node with the left max val or right min
                int leftMax = maxFromLeft(root->left);
                root->val = leftMax;
                root->left = deleteNode(root->left,leftMax);
                return root;
            }else if(root->left){ // single branch
                return root->left;
            }else if(root->right){
                return root->right;
            }else{
                return NULL;
            }
        }
        return root;
    }
};