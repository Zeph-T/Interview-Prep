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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL or root->left == NULL and root->right ==  NULL)return 0;
        stack<TreeNode*>st;
        st.push(root);
        int ans = 0;
        unordered_map<TreeNode*,int>map;
        while(!st.empty()){
            TreeNode* node = st.top();
            if(node->left and map.count(node->left) == 0)st.push(node->left);
            else if(node->right and map.count(node->right) == 0)st.push(node->right);
            else{
                TreeNode* curr = st.top();st.pop();
                int leftMax = map[curr->left];
                int rightMax = map[curr->right];
                map[curr] = 1 + max(leftMax , rightMax);
                ans = max(ans , leftMax + rightMax);
            }
        }
        return ans;
    }
};