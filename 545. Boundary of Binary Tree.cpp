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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        print_left(root, ans);
        print_leaves(root, ans);
        print_right(root, ans);
        return ans;
    }

    void print_left(TreeNode* root, vector<int> &ans) {
        ans.push_back(root->val);
        visited.insert(root);
        if (root->left) {
            print_left(root->left, ans);
        } else if (root->right) {
            print_left(root->right, ans);
        }
    }

    void print_leaves(TreeNode* root, vector<int> &ans) {
        if (root->left == NULL && root->right == NULL && visited.find(root) == visited.end()) {
            ans.push_back(root->val);
            visited.insert(root);
        } else {
            if (root->left)
                print_leaves(root->left, ans);
            if (root->right)
                print_leaves(root->right, ans);
        }
    }

    void print_right(TreeNode* root, vector<int> &ans) {
        if (root->right) {
            print_right(root->left, ans);
        } else if (root->left) {
            print_right(root->right, ans);
        } else if (visited.find(root) == visited.end()) {
            ans.push_back(root->val);
            visited.insert(root);
        }
    }
private:
    set<TreeNode*> visited;
};
