/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans =0;
    int dfs(Node* root){
        if(root == NULL)return 0;
        int maxOne = 0;
        int maxTwo = 0;
        
        for(auto node : root->children){
            if(node == NULL)continue;
            int diameter = dfs(node);
            if(diameter > maxOne){
                maxTwo = maxOne;
                maxOne = diameter ;
            }
            else if(diameter > maxTwo)maxTwo = diameter; 
        }
        
        ans = max(ans , maxOne + maxTwo + 1);
        return maxOne + 1;
    }
    
    
    int diameter(Node* root) {
        if(root)dfs(root);
        if(ans == 0)return 0;
        return ans - 1;
    }
};