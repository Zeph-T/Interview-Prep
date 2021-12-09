



/**
 * -1 -> need a camera
 *  0 -> have a camera
 *  1 -> already covered
 */
class Solution {
public:
    int cameras = 0;
    
    int solve(TreeNode* root){
        if(root == NULL)return 1; // meaning  covered
        int lc = solve(root->left);
        int rc = solve(root->right);
        if(lc == -1 or rc == -1){ // need a camera
            cameras++;
            return 0;
        }
        
        if(lc == 0 or rc == 0)return 1; // you have a camera
        return -1;
        
        
    }
    
    
    int minCameraCover(TreeNode* root) {
        if(solve(root) == -1)cameras++;
        return cameras;
    }
};






/**
 */
class Solution {
public:
    unordered_set<TreeNode*>covered;
    int count = 0;
    
    
    void dfs(TreeNode* root,TreeNode* parent){
        if(root == NULL)return ;
        
        dfs(root->left,root);
        dfs(root->right,root);
        
        if(parent == NULL and !covered.count(root) or !covered.count(root->left) or !covered.count(root->right)){
            count++;
            covered.insert(parent);
            covered.insert(root);
            covered.insert(root->left);
            covered.insert(root->right);
        } 
        
        
    }
    
    int minCameraCover(TreeNode* root) {
        covered.insert(NULL);
        dfs(root,NULL);
        return count;
    }
};