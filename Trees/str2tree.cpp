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
    TreeNode* str2tree(string s) {
        stack<TreeNode*>st;
        int i=0 , n = s.size();
        if(n == 0)return NULL;
        while(i < n){
            if(s[i] == '-' or isdigit(s[i])){ // we check if the char is a number
                int startIndex = i;
                int endIndex = i+1;
                while(endIndex < n and isdigit(s[endIndex]))endIndex++; // extract the number
                int node_val = stoi(s.substr(startIndex,endIndex));
                TreeNode* newNode = new TreeNode(node_val); // create the node
                
                if(!st.empty()){ //if the stack is not empty, means their are some nodes inside the stack which the newNode can be a child to.
                    TreeNode* node = st.top();
                    if(node->left == NULL){
                        node->left = newNode;
                    }else{
                        node->right = newNode;
                    }
                }
                st.push(newNode); // we push the node to the stack
                i = endIndex; 
                continue;
                
            }else if(s[i] == ')'){ // means one node has completed its execution
                st.pop();
            }
            i++;
        }
        return st.top();
    }
};