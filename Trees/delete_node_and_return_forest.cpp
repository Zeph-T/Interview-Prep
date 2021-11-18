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
    vector<TreeNode*>newNodes;
    
    
    TreeNode* dfs(TreeNode* root,set<int>&numbers){
        if(root == NULL)return NULL;
        root->left = dfs(root->left , numbers);
        root->right = dfs(root->right,numbers); // bottom up approach
        
        if(numbers.find(root->val) != numbers.end()){ // if the value is present in the set
            if(root->left){ //their will be two seperate nodes of children since the connections are remvoed
                newNodes.push_back(root->left);
            }
            if(root->right){
                newNodes.push_back(root->right);
            }
            return NULL; // meaning that , the node is removed
        }
        return root;
    }
    
    
    
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int>numbers(to_delete.begin(),to_delete.end());
        dfs(root,numbers);
        if(numbers.find(root->val) == numbers.end())newNodes.push_back(root);
        return newNodes;
    }
};