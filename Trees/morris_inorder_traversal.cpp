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
    
    TreeNode* getRightMost(TreeNode* node,TreeNode* root){
        while(node->right != NULL and node->right != root)node = node->right;
        return node;
    }    
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            TreeNode* lNode = curr->left;
            if(lNode == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
               TreeNode* rightMost = getRightMost(lNode,curr);
                if(rightMost->right == NULL){
                    rightMost->right = curr;
                    curr = curr->left;
                }else{
                    rightMost->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
            
        }
        return ans;
    }
};