TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == NULL)
        return NULL;
    bool in_left = contain(root->left, p, q);
    bool in_right = contain(root->right, p, q);
    if(in_left && in_right)
        return root;
    else if((root == p || root == q) && (in_left || in_right))
        return root;
    else
        in_left ? lowestCommonAncestor(root->left, p, q) : lowestCommonAncestor(root->right, p, q);
}

bool contain(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == p || root == q)
        return true;
    if(root == NULL)
        return false;
    return contain(root->left, p, q) || contain(root->right, p, q);
}
