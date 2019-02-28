/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == NULL || t2 == NULL) {
            return t1 == NULL ? t2 : t1;
        }
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push(make_pair(t1, t2));
        while(!st.empty()) {
            TreeNode* a = st.top().first;
            TreeNode* b = st.top().second;
            st.pop();
            if (b == NULL) {
                continue;
            }
            if (a->left != NULL) {
                st.push(make_pair(a->left, b->left));
            } else {
                a->left = b->left;
            }
            if (a->right != NULL) {
                st.push(make_pair(a->right, b->right));
            } else {
                a->right = b->right;
            }
        }
        return t1;
    }
};
