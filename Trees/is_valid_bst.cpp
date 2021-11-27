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
    bool valid(TreeNode* root,long minVal,long maxVal){
        if(root == NULL)return true;
        int val = root->val;
        if(val <= minVal or val >= maxVal)return false;
        return valid(root->left,minVal ,val) and valid(root->right , val , maxVal);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN,LONG_MAX);
    }
};