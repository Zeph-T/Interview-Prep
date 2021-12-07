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
    int ans = 0;
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        int leftSum = dfs(root->left);
        int rightSum = dfs(root->right);
        
        ans += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
        
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};