bool isValidBST(TreeNode* root) 
{
	if(root == NULL)
		return true ;
	else
	{
        TreeNode* left_iter = root->left ;
        while(left_iter != NULL && left_iter->right != NULL)
            left_iter = left_iter->right ;
        int left_val = left_iter == NULL? INT_MIN : left_iter->val ;
        
        TreeNode* right_iter = root->right ;
        while(right_iter != NULL && right_iter->left != NULL)
            right_iter = right_iter->left ;
        int right_val = right_iter == NULL? INT_MAX : right_iter->val ;
        
	    if((left_val < root->val || left_iter == NULL) && (right_val > root->val || right_iter == NULL))
			return isValidBST(root->left)&&isValidBST(root->right) ;
		else
			return false ;		
	}        
}