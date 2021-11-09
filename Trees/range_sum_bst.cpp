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
    void dfs(TreeNode* root,int low,int high){
        if(root != NULL){
            if(root->val >= low and root->val <= high){
                ans += root->val;
            }
            if(root->val >= low)
                dfs(root->left,low,high);
            if(root->val <= high)
                dfs(root->right,low,high);
        }
        return ;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        dfs(root,low,high);
        return ans;
    }
};