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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr or !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->val);
                curr = node->right;
            }
        }
        return ans;
        
    }
};