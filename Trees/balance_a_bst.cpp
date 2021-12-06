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
    vector<TreeNode*> nodes;
    
    void dfs(TreeNode* root){
        if(root == NULL)return ;
        dfs(root->left);
        nodes.push_back(root);
        dfs(root->right);
        return ;
    }
    
    TreeNode* build(int left, int right){
        if(left > right)return NULL;
        
        
        int mid = (left + right)/2;
        TreeNode* root = nodes[mid];
        root->left  = build(left,mid-1);
        root->right = build(mid+1,right);
        return root;
        
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);   
        return build(0,nodes.size() - 1);
    }
};