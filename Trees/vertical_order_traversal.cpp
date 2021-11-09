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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        queue<pair<TreeNode*,pair<int,int>>>q;
        vector<vector<int>>ans;
        if(root == NULL)return ans;
        q.push({root,{0,0}});
        map<int,vector<int>>mp;
        while(!q.empty()){
            int row = q.front().second.first;
            int level = q.front().second.second;
            TreeNode* node = q.front().first;
            q.pop();
            mp[level].push_back(node->val);
            if(node->left)q.push({node->left,{row+1,level-1}});
            if(node->right)q.push({node->right,{row+1,level+1}});
        }
        for(auto x: mp){
            vector<int>temp;
            for(int p : x.second)
                temp.push_back(p);
            ans.push_back(temp);
        }
        return ans;
    }
};