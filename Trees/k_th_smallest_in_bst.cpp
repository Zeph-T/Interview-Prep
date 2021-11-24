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
    int k = 0;
    int ans = 0;
    
    void dfs(TreeNode* root){
        if(root == NULL)return ;

        if(root->left)dfs(root->left);
        k--;
        if(k == 0){
            ans = root->val;
            return ;
        }
        if(root->right)dfs(root->right);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        if(root == NULL)return -1;
        dfs(root);
        return ans;
    }
};