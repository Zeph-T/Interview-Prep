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
    int sum  = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root == NULL)return NULL;
        
        convertBST(root->right); // get the sum of all right nodes;
        sum += root->val; // add the values to the sum
        root->val = sum; // while traversing back, we will have all the values greater than the root val as we traversed the right subtree
        convertBST(root->left); // then we call the left subtree
        
        return root;
        
    }
};


TreeNode* convertBST(TreeNode* root) {
    int sum = 0;
    stack<TreeNode*>st;
    TreeNode* node = root;
    while(!st.empty() or node){
        while(node){
            st.push(node);
            node = node->right;
        }
        node = st.top();st.pop();
        sum += node->val;
        node->val = sum;
        node = node->left;
    }
    return root;
}