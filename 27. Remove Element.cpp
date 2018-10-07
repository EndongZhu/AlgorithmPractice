int removeElement(vector<int>& nums, int val) 
{
	int size = nums.size()
	if(size == 0) 
		return 0 ;
	int bias = 0 ;
	int len = 0 ; 
	for(int i = 0 ; i < size ; i++)
	{
		nums[i-bias] = nums[i] ;
		if(nums[i] == val)
		{
			++bias ;
			++len ;
		}
	}
	return len ;
}