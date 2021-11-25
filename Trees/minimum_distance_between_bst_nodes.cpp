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
    int prevVal = INT_MIN;
    int ans = INT_MAX;
    
    
    void dfs(TreeNode* root){ 
        if(!root)return ;
        dfs(root->left);
        if(prevVal != INT_MIN){
            ans = min(ans , abs(root->val - prevVal));
        }
        prevVal = root->val; // update the prev val such that it will be used for their child
        dfs(root->right);
    }
    
    
    int minDiffInBST(TreeNode* root) {
        if(root == NULL)return -1;
        dfs(root);
        return ans;
    }
};