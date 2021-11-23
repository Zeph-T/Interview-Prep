/**
Time Complexity  : O(N)
Space Complexity : O(N)
 */
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL)return ;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
        return ;
    }
};


/**
Time Complexity : O(N)
Space Complexity : O(N)
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        stack<TreeNode*>st;
        if(root == NULL)return ;
        st.push(root);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->right)st.push(node->right);
            if(node->left)st.push(node->left);
            if(!st.empty())
                node->right = st.top();
            node->left = NULL;
        }
    }
};

/*
Time Complexity : O(N)
Space Complexity : O(1)
Intuition : We only have to rearrange all the left nodes to the right of the current node and make the right nodes of the current node point to left
*/

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        while(curr){
            if(curr->left){
                TreeNode* prev = curr->left;
                while(prev->right)prev = prev->right; // if the left subtree has the right nodes, go to the deepest level as we have to connect that node to the current node's right
                prev->right = curr->right; // after getting the node rearrange the links as the right of the deepest node will point to the current node right
                curr->right = curr->left; // the current node right will be updated to left as we have to traverse the curr left nodes as well 
                curr->left = NULL; // since the left is fixed for the current node as the left is updated to be the right node , it will be set to NULL
            }
            curr = curr->right; // this makes sure that since we updated the right node to be the left node, we will indeed traverse in the left subtree at start
        }
    }
};