/**
Get both the sorted order using inorder traversal which takes up O(M + N) Time Complexity 
Sort the order thati is O(M+ N)
Space Complexity : O(M + N)
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int>&ans){
        if(root == NULL)return ;
        dfs(root->left,ans);
        ans.push_back(root->val);
        dfs(root->right,ans);
        return ;
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        vector<int>arr2;
        dfs(root1,arr1);
        dfs(root2,arr2);
        
        vector<int>ans;
        int n1 = arr1.size(); int n2 = arr2.size() ; int i = 0 ; int j = 0;
        while(i < n1 and j < n2){
            if(arr1[i]  > arr2[j]){
                ans.push_back(arr2[j]);
                j++;
            }else{
                ans.push_back(arr1[i]);
                i++;
            }
        }
        
        while(i < n1){
            ans.push_back(arr1[i]);i++;
        }
        
        while(j < n2){
            ans.push_back(arr2[j]);j++;
        }
        return ans;
        
    }
};