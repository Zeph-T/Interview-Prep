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
    vector<int>coins;
    int count = 0;
    int dfs(TreeNode* root){
        if(root == NULL)return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        count += abs(left) + abs(right); // give or take
        return root->val + left + right - 1; // excess count
    }
    
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return count;
    }
};