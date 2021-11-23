/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)return "";
        queue<TreeNode*>q;
        string res="";
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)res+="#,";
            else res+=to_string(node->val)+",";
            if(node){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)return NULL;
        stringstream s(data);
        string str;
        getline(s,str,','); // acts as a dilimter till we encounter a ,
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(s,str,',');
            if(str == "#"){
                node->left = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(str));
                node->left = newNode;
                q.push(newNode);
            }
            
            getline(s,str,',');
            if(str == "#"){
                node->right = NULL;
            }else{
                TreeNode* newNode = new TreeNode(stoi(str));
                node->right = newNode;
                q.push(newNode);
            }
        }
        return root;        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));