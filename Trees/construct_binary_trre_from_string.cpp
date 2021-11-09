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
    TreeNode* str2tree(string s) {
        if(s.size() == 0)return NULL;
        stack<TreeNode*>st;
        int idx = 0;
        int n = s.size();
        while(idx < n ){
            char ch = s[idx];
            if(isdigit(ch) or ch == '-'){
                int startIdx = idx;
                int endIdx = idx+1;
                while(endIdx < s.size() and isdigit(s[endIdx]))endIdx++;
                int nodeVal = stoi(s.substr(startIdx,endIdx));
                TreeNode* node = new TreeNode(nodeVal);
                if(!st.empty()){
                    TreeNode* root = st.top();
                    if(root->left == NULL)root->left = node;
                    else root->right = node;
                }
                st.push(node);
                idx = endIdx;
                continue;
            }else if(ch == ')')st.pop();
            idx++;
        }
        return st.top();
    }
};