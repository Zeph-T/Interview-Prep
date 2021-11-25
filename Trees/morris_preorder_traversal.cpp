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
    
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr = root;
        while(curr){
            TreeNode* leftNode = curr->left;
            if(leftNode == NULL){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* rightMost = getRightMost(leftNode,curr);
                if(rightMost->right == NULL){
                    ans.push_back(curr->val);
                    rightMost->right = curr;
                    curr = curr->left;
                }else{
                    rightMost->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};