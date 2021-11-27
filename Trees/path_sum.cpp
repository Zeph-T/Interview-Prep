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
    
    bool dfs(TreeNode* root,int target){
        if(root == NULL)return false;
        
        
        target -= root->val;
        if(root->left == NULL and root->right == NULL)return target == 0;
        bool fromLeft = dfs(root->left , target);
        bool fromRight = dfs(root->right , target);
        return fromLeft or fromRight;
        
        
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return dfs(root,targetSum);
    }
};