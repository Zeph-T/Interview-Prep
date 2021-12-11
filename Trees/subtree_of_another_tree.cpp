class Solution {
public:
    bool symmetric(TreeNode* root1,TreeNode* root2){
        if(root1 == NULL and root2 == NULL)return true;
        if(root1 == NULL or root2 == NULL)return false;
        return root1->val == root2->val and symmetric(root1->left,root2->left) and symmetric(root1->right,root2->right);
    }
    
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL or subRoot == NULL)return false;
        if(root->val == subRoot->val and symmetric(root,subRoot))return true;
        return isSubtree(root->left,subRoot) or isSubtree(root->right,subRoot);
    }
};