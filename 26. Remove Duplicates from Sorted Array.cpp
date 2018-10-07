int removeDuplicates(vector<int>& nums) 
{
	int size = nums.size()
	if(size == 0) 
		return 0 ;
	int cur = nums[0] ;
	int len = 1 ;
	for(int i = 1 ; i < size; i++)
	{
		if(nums[i] != cur)
		{
			len++ ;
			cur = nums[i] ;
		}
	}
	return len ;
}