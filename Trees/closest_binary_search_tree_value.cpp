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
    int closestValue(TreeNode* root, double target) {
        int closest = root->val;
        while(root){
            closest = abs(root->val - target) < abs(closest - target) ?  root->val : closest; // check if the present node when subtracted with the targets gives less value compared to the closest till now 
            if(target < root->val){
                root = root->left;
            } else{
                root= root->right;
            }
        }
        return closest;
    }
};