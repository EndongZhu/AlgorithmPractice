int removeDuplicates(vector<int>& nums) 
{
	int len = nums.size() ;
	if(len <= 2)
		return len ;
	int cur = nums[0] ;
	int cnt = 1 ;
	for(int i = 1 ; i < nums.size() ; i++)
	{
		if(nums[i] == cur)
		{
			cnt++ ;
			if(cnt > 2)
			{
				nums.erase(nums.begin()+i) ;
				i-- ;
			}
		}
		else
		{
			cur = nums[i] ;
			cnt = 1 ;
		}
	}
}