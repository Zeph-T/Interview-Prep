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
class CBTInserter {
public:
    queue<TreeNode*>q;
    TreeNode* root;
    TreeNode* lastNode = NULL;
    CBTInserter(TreeNode* root) {
        this->root = root;
        q.push(root);
        while(!q.empty()){
            TreeNode* source = q.front();
            if(source->left){
                q.push(source->left);
            }else{
                lastNode = source;
                break;
            }
            if(source->right){
                q.push(source->right);
            }else{
                lastNode = source;
                break;
            }
            q.pop();
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        int value = lastNode->val;
        if(lastNode->left == NULL){
            lastNode->left = newNode;
            q.push(newNode);
        }else{
            lastNode->right = newNode;
            q.push(newNode);
            q.pop();
            lastNode = q.front();
        }
        return value;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */