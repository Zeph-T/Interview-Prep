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

struct Pair{
    int withRobbery;
    int withoutRobbery;
};

class Solution {
public:    
    Pair dfs(TreeNode* root){      
        if(root == NULL)return {0,0};
        Pair left = dfs(root->left);
        Pair right = dfs(root->right);
        Pair ans = {0,0};
        ans.withRobbery = left.withoutRobbery + right.withoutRobbery + root->val;
        ans.withoutRobbery = max(left.withRobbery , left.withoutRobbery) + max(right.withRobbery ,right.withoutRobbery);
        return ans;
    }
    
    
    int rob(TreeNode* root) {
        Pair result = dfs(root);
        return max(result.withRobbery , result.withoutRobbery);
    }
};