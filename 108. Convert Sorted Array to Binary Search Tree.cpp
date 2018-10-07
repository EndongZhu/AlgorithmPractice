TreeNode* sortedArrayToBST(vector<int>& nums) 
{
	int len = nums.size() ;
	if(len == 0)
		return NULL ;
	TreeNode* res = buildTree(nums,0,len-1) ;
	return res ;
}

TreeNode* buildTree(vector<int>& nums, int start, int end)
{
	if(start > end || start < 0 || end < 0)
		return NULL ;
	int mid = (start+end+1)/2 ;
	int mid_val = nums[mid] ;
	TreeNode* cur = new TreeNode(mid_val) ;
	cur->left = buildTree(nums,start,mid-1) ;
	cur->right = buildTree(nums,mid+1,end) ;

	return cur ;
}