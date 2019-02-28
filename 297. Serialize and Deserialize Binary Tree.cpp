class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            TreeNode* cur = que.front();
            que.pop();
            if(cur != NULL) {
                que.push(cur->left);
                que.push(cur->right);
                stringstream ss;
                ss << cur->val;
                ans += ss.str() + " ";
            }
            else {
                ans += "NULL ";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == "")
            return NULL;
        vector<string> split;
        while(data != "") {
            int pos = 0;
            while(pos < data.size() && data[pos] != ' ')
                pos++;
            string cur = data.substr(0, pos);
            string remain = data.substr(pos+1);
            split.push_back(cur);
            data = remain;
        }
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(stoi(split[0], nullptr, 10));
        que.push(root);
        for(int i = 1; i < split.size(); i+=2) {
            TreeNode* left_tr = split[i] == "NULL" ? NULL : new TreeNode(stoi(split[i], nullptr, 10)) ;
            TreeNode* right_tr  = split[i+1] == "NULL" ? NULL : new TreeNode(stoi(split[i+1], nullptr, 10)) ;
            TreeNode* cur = que.front();
            que.pop();
            cur->left = left_tr;
            cur->right = right_tr;
            if(left_tr != NULL)
                que.push(left_tr);
            if(right_tr !=  NULL)
                que.push(right_tr);
        }
        return root;
    }
};
