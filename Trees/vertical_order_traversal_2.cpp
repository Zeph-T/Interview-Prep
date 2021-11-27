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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        map<int,map<int,multiset<int>>>mp;
        while(!q.empty()){
            int len = q.size();
            for(int i=0;i<len;i++){
                int level = q.front().second.second;
                int row = q.front().second.first;
                TreeNode* node = q.front().first;
                q.pop();
                mp[level][row].insert(node->val);
                
                if(node->left)q.push({node->left , {row + 1, level - 1}});
                if(node->right)q.push({node->right,{row + 1, level + 1}});
            }
        }
        for(auto order : mp){
            vector<int>temp;
            for(auto col : order.second){
                for(int val : col.second)temp.push_back(val);
            }
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};