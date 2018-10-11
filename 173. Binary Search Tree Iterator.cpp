class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        leftIn(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stack.top();
        stack.pop();
        if(cur->right)
            leftIn(cur->right);
        return cur->val;
    }
private:
    Stack<TreeNode*> stack;
    void leftIn(TreeNode* root) {
        while(root) {
            Stack.push(root);
            root = root->left;
        }
        return;
    }
};
