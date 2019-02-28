bool isValidBST(TreeNode* root) {
    stack<TreeNode*> st;
    st.push(root);
    
    TreeNode* prev = NULL;
    while(root!=NULL && !st.empty()) {
        while(root!=NULL) {
            st.push(root);
            root = root->left;
        }
        root = st.top();
        st.pop();
        if(!prev && root->val <= prev->val)
            return false;
        prev = root;
        root = root->right;
    }
    return true;
}
