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
    
    void solve(TreeNode* root,int count,int target,int &ans){
        if(!root)return ;
        if(root->val == target){
            count++;
            ans = max(ans , count);
        }else{
            count = 1;
        }
        if(root->left)solve(root->left,count,root->val + 1,ans);
        if(root->right)solve(root->right,count,root->val +1,ans);
        return ;
    }
    
    int longestConsecutive(TreeNode* root) {
        int ans = 0;
        solve(root,0,-1,ans);
        return ans;
    }
};