#include<string>
#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
#include<string>
using namespace std ;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
TreeNode* buildTree(vector <int> & preorder, vector <int> & inorder) 
{
	int cur_val = preorder[0] ;
	TreeNode* cur = new TreeNode(cur_val) ;
    if(preorder.size() <= 1 || inorder.size() <= 1)
		return cur ;

	int pos = 0 ;
	for(int i = 0 ; i < inorder.size() ; i++)
	{
		if(inorder[i] == cur_val)
		{
			pos = i ;
			break ;
		}
	}
	int left_size = pos ;
	int right_size = inorder.size()-pos-1 ;

	vector<int> left_preorder (preorder.begin()+1, preorder.begin()+left_size+1) ;
	vector<int> left_inorder (inorder.begin(),inorder.begin()+left_size) ;
	vector<int> right_preorder (preorder.begin()+left_size+1, preorder.end()) ;
	vector<int> right_inorder (inorder.begin()+left_size+1,inorder.end()) ;

	cur->left = buildTree(left_preorder,left_inorder) ;
	cur->right = buildTree(right_preorder,right_inorder) ;

	return cur ;
}

void print_vec(vector <int> & v)
{
	for(int i = 0 ; i < v.size() ; i++)
	{
		cout << v[i] << " " ;
	}
	cout << endl ;
}
};

string treeNodeToString(TreeNode* root) {
    if (root == NULL) {
      return "[]";
    }

    string output = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node == NULL) {
          output += "null, ";
          continue;
        }

        output += ('0'+node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    
    vector<int> preorder ; preorder.push_back(3) ; preorder.push_back(9) ; preorder.push_back(20) ; preorder.push_back(15) ; preorder.push_back(7) ;
    vector<int> inorder ; inorder.push_back(9) ; inorder.push_back(3) ; inorder.push_back(15) ; inorder.push_back(20) ; inorder.push_back(7) ;
    
    TreeNode* ret = Solution().buildTree(preorder, inorder);

    string out = treeNodeToString(ret);
    cout << out << endl;
    
    return 0;
}
