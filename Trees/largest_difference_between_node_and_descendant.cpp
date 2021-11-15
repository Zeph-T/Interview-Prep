/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

int ans ;

void find(Tree* root,int minval , int maxval){
    ans = max(ans , max(abs(root->val - minval) , abs(root->val - maxval))); // the difference can be between the nodeval and the max_element in the subtree or the min_element of the subtree
    int newMin  =min(root->val , minval); // update the min_val till now
    int newMax = max(root->val , maxval); // update the max_val till now
    if(root->left)find(root->left ,newMin , newMax ); // go to the left subtree with the updated min and max
    if(root->right)find(root->right , newMin , newMax);  // go to the right subtree with the updated min and max;
}

int solve(Tree* root) {
    ans = 0;
    if(root == NULL)return 0;
    find(root,root->val,root->val);
    return ans;
}