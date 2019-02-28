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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return root;
        if (root->val < L) {
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            return trimBST(root->left, L, R);
        } else if (root->left == NULL || root->left->val < L) {
            root->left = NULL;
            root->right = trimBST(root->right, root->val, R);
        } else if (root->right == NULL || root->right->val > R) {
            root->right = NULL;
            root->left = trimBST(root->right, L, root->val);
        } else {
            root->left = trimBST(root->left, L, root->val);
            root->right = trimBST(root->right, root->val, R);
        }
        return root;
    }
};
