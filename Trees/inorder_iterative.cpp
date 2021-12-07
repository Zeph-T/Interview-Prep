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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)return {};
        vector<int>ans;
        stack<TreeNode*>st;
        TreeNode* curr = root;
        while(curr or !st.empty()){
            if(curr){
                st.push(curr);
                curr = curr->left;
            }else{
                TreeNode* node = st.top();
                st.pop();
                ans.push_back(node->val);
                curr = node->right;
            }
        }
        return ans;
        
    }
};




/*
Using Morris Traversal
Time Complexity : O(N)
Space Complexity : O(N)
*/

class Solution {
public:
    Node* getRightMost(Node* node,Node* curr){
        while(node->right and node->right != curr)node = node->right;
        return node;
    }
    
    
    Node* treeToDoublyList(Node* root) {
        if(root == NULL)return NULL;
        Node* dummy = new Node(-1);
        Node* prev = dummy;
        Node* curr = root;
        while(curr){
            if(curr->left){
                Node* rightMostNode = getRightMost(curr->left,curr);
                if(rightMostNode->right == NULL){
                    rightMostNode->right = curr;
                    curr = curr->left;
                }else{
                    rightMostNode->right = NULL;
                    prev->right = curr;
                    curr->left = prev;
                    prev = curr;
                    curr = curr->right;
                }
            }else{
                prev->right = curr;
                curr->left = prev;
                prev = curr;
                curr = curr->right;
            }
        }
        Node* newHead = dummy->right;
        newHead->left = prev;
        prev->right = newHead;
        return newHead;
        // return NULL;
    }
};