int node_cnt(TreeNode* nd) {
    if(nd == NULL)
        return 0 ;
    else
        return 1 + node_cnt(nd->left) + node_cnt(nd->right) ;
}

int kthSmallest(TreeNode* root, int k) {
    int left_cnt = node_cnt(root->left) ;
    if(left_cnt == k-1)
        return root->val ;
    else if(left_cnt < k-1)
        return kthSmallest(root->right, k - left_cnt - 1) ;
    else
        return kthSmallest(root->left, k) ;
}
