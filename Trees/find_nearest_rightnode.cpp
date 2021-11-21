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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<TreeNode*>q;
        if(root == NULL)return NULL;
        q.push(root);
        int target = u->val;
        while(!q.empty()){
            bool found = false;
            TreeNode* node;
            int len = q.size();
            for(int i=0;i<len;i++){
                node = q.front();
                if(found == true)return q.front();
                q.pop();
                if(node->val == target)found = true;
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            if(found)return NULL;
        }
        return NULL;
    }
};