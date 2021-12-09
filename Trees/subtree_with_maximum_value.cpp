
int dfs(Tree* root , int &ans ){
    if(root == NULL)return 0;
    int current = root->val + dfs(root->left , ans) + dfs(root->right , ans);

    ans = max(ans , current);
    return current;
}

int solve(Tree* root) {
    int ans = INT_MIN;
    dfs(root , ans);
    return  ans < 0 ? 0 : ans;
}