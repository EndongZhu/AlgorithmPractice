vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    if(root == NULL)
        return ans;
    dfs(root, ans, "");
    return ans;
}

void dfs(TreeNode* root, vector<string>& ans, string path) {
    if(root->left == NULL && root->right == NULL) {
        path = path + to_string(root->val);
        ans.push_back(path);
        return;
    }
    path = path + to_string(root->val) + "->";
    if(root->left != NULL) {
        dfs(root->left, ans, path);
    }
    if(root->right != NULL) {
        dfs(root->right, ans, path);
    }
}
