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

struct Info{
    int sum;
    int max;
    int min;
    bool isBST;
};
class Solution {
public:
    int ans = INT_MIN;
    Info solve(TreeNode* root){
        if(root == NULL)return {0,INT_MIN,INT_MAX,true};
        if(root->left == NULL and root->right == NULL)return {root->val , root->val,root->val,true};
        Info left = solve(root->left);
        Info right = solve(root->right);
        Info current;
        current.sum = 0;
        if(left.isBST and right.isBST and left.max < root->val and right.min > root->val){
            current.min = min(left.min , min(right.min , root->val));
            current.max = max(left.max , max(right.max , root->val));
            current.sum =  root->val + left.sum + right.sum;
            ans = max(ans , current.sum);
            current.isBST = true;
            return current;
        }else{
            current.sum = max(left.sum , right.sum);
            ans = max(ans , current.sum);
            current.isBST = false;
        }
        return current;
    }
    
    
    int maxSumBST(TreeNode* root) {
        solve(root);
        return ans > 0 ? ans : 0;
    }
};