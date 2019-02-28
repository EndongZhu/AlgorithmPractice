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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        mem.clear();
        vector<TreeNode*> ans;
        traversal(root);
        for (auto iter = mem.begin(); iter != mem.end(); ++iter) {
            if (iter->second.size() > 1) {
                ans.push_back(iter->second.front());
            }
        }
        return ans;
    }

    string traversal(TreeNode* root) {
        if (root == NULL) {
            return "null";
        } else {
            string ans = to_string(root->val) + " " + traversal(root->left)
                + " " + traversal(root->right);
            if (mem.find(ans) != mem.end()) {
                mem[ans].push_back(root);
            } else {
                vector<TreeNode*> temp;
                temp.push_back(root);
                mem[ans] = temp;
            }
            return ans;
        }
    }
private:
    unordered_map<string, vector<TreeNode*>> mem;
};
