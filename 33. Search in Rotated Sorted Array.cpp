int search(vector<int>& nums, int target) 
{
	int len = nums.size() ;
	if(len == 0)
		return -1 ;
	if(len == 1)
	{
		if(nums[0] == target)
			return 0 ;
		else
			return -1 ;
	}	        

	int pos = len ;
	for(int i = 1 ; i < len ; i++)
	{
		int num1 = nums[i] ;
		int num2 = nums[i-1] ;
		if(num1 < num2)
		{
			pos = i ;
		}
	}

	int a = 0 , b = pos , c = len-1 ;
	int head = a , tail = b-1 ;
	while(head <= tail)
	{
		int mid = (head+tail)/2 ;
		if(nums[mid] == target)
		{
			return mid ;
		}
		else if(nums[mid] > target)
		{
			tail = mid-1 ;
		}
		else
		{
			head = mid+1 ;
		}
	}
	head = b , tail = c ;
	while(head <= tail)
	{
		int mid = (head+tail)/2 ;
		if(nums[mid] == target)
		{
			return mid ;
		}
		else if(nums[mid] > target)
		{
			tail = mid-1 ;
		}
		else
		{
			head = mid+1 ;
		}
	}
	return -1 ;
}