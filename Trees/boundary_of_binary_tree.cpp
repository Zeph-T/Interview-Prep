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
    vector<int>ans;
    
    void printLeft(TreeNode* root){
        if(root == NULL)return ;
        if(root->left){
            ans.push_back(root->val);
            printLeft(root->left);
        }else if(root->right){
            ans.push_back(root->val);
            printLeft(root->right);
        }
    }
    
        
    void printRight(TreeNode* root){
        if(root == NULL)return ;
        if(root->right){
            printRight(root->right);
            ans.push_back(root->val);
        }else if(root->left){
            printRight(root->left);
            ans.push_back(root->val);
        }
    }
    
    void printBoundary(TreeNode* root){
        if(root == NULL)return ;
        printBoundary(root->left);
        printBoundary(root->right);
        if(root->left == NULL and root->right == NULL){
            ans.push_back(root->val);
        }
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(root == NULL)return ans;
        ans.push_back(root->val);
        printLeft(root->left);
        printBoundary(root->left);
        printBoundary(root->right);
        printRight(root->right);
        return ans;
    }
};