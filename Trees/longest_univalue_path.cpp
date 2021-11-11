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
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        int left = dfs(root->left); // traverse the left subtree
        int right = dfs(root->right); // traverse the right subtree
        int aleft = 0;
        int aright = 0; 
        if(root->left and root->val == root->left->val){
            aleft += left + 1; // if the root value is the same as root->left->val then, there is a increase in the count
        }
        if(root->right and root->val == root->right->val){
            aright += right + 1; // // if the root value is the same as root->left->val then, there is a increase in the count
        }
        ans = max(ans , aleft + aright); // update the final answer
        return max(aleft,aright); // return the max of both paths 
        
    }
public:
    int ans = 0;
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};