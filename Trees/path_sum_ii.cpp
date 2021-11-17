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
    vector<vector<int>>ans;
    
    void dfs(TreeNode* root,int targetSum,vector<int>&temp){
        if(root == NULL)return ;
        targetSum -= root->val;
        temp.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            if(targetSum == 0)ans.push_back(temp);
        }else{
            dfs(root->right,targetSum,temp);
            dfs(root->left,targetSum,temp);   
        }
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        dfs(root,targetSum,temp);
        return ans;
    }
};