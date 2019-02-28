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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        unordered_map<int, vector<int>> mem;
        int left = INT_MAX;
        int right = INT_MIN;
        interpret(mem, left, right, root);
        vector<vector<int>> ans;
        for (int i = left; i <= right; i++) {
            vector<int> v(mem[i]);
            ans.push_back(v);
        }
        return ans;
    }

    void interpret(unordered_map<int, vector<int>>& mem, int& min_col, int& max_col, TreeNode* root) {
        if (root == NULL) {
            return;
        }
        queue<pair<TreeNode*,int>> que;
        que.push(make_pair(root, 0));
        while(!que.empty()) {
            TreeNode* cur = que.front().first;
            int col = que.front().second;
            que.pop();
            if (cur == NULL) {
                continue;
            }
            if (mem.find(col) == mem.end()) {
                vector<int> v;
                mem[col] = v;
            }
            if (col > max_col) {
                max_col = col;
            }
            if (col < min_col) {
                min_col = col;
            }
            mem[col].push_back(cur->val);
            que.push(make_pair(cur->left, col-1));
            que.push(make_pair(cur->right, col+1));
        }
    }
};
