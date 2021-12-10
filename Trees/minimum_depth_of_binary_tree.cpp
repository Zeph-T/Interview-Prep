int Solution::minDepth(TreeNode* root) {
    if(root == NULL)return 0;
    if(root->left == NULL and root->right == NULL)return 1;
    int depth = INT_MAX;
    if(root->left) depth = min(depth , minDepth(root->left));
    if(root->right)depth = min(depth , minDepth(root->right));
    return depth + 1;
}


