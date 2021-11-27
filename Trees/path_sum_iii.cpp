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
    unordered_map<int,int>prefix;
    int ans = 0;
    void solve(TreeNode* root,int target,int sum){
        if(root == NULL)return ;
        sum += root->val;
        if(sum == target)ans++;
        ans += prefix[sum - target];
        prefix[sum]++; // add the curent sum to the prefix 
        solve(root->left,target,sum);
        solve(root->right,target,sum);
        prefix[sum]--; // remove the prefix sum as we moved past the branch with root as the current root
        return ;
    }
    
    
    int pathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum,0);
        return ans;
    
    }
};