//User function Template for C++
#include<bits/stdc++.h>
// Structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
//Function to count number of subtrees having sum equal to given sum.
int dfs(Node* root,int target,int &ans){
    if(root == NULL)return 0;
    int lsum = dfs(root->left,target,ans);
    int rsum = dfs(root->right,target,ans);
    if(lsum + rsum + root->data == target)ans++;
    return lsum + rsum + root->data;
}


int countSubtreesWithSumX(Node* root, int X)
{
    int ans = 0;   
    dfs(root,X,ans);
    return ans;
	// Code here
}
