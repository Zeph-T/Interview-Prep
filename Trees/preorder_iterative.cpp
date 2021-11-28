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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        TreeNode* curr = root;
        while(!st.empty()){
            if(curr){
                st.push(curr);
                ans.push_back(curr->val);
                curr = curr->left;
            }else{
                curr = st.top()->right;
                st.pop();
            }
        }
        return ans;
    }
};