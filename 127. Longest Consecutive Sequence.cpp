int longestConsecutive(vector<int>& nums) 
{
	int size = nums.size() ;
	
	map<int,int> hash ;
	for(int i = 0 ; i < size; i++)
	{
		if(hash.find(nums[i]) != hash.end())
		{
			continue ;
		}
		else if(hash.find(nums[i]-1) != hash.end())
		{
			int start = nums[i]-hash[nums[i]-1] ;
			int end = nums[i] ;
			int val = hash[nums[i]-1]+1 ;
			if(hash.find(nums[i]+1) != hash.end())
			{
				val += hash[nums[i]+1] ;
				end = start+val-1 ;
			}
			hash[start] = val ;
			hash[end] = val ;
			hash[nums[i]] = val ;
		}
		else if(hash.find(nums[i]+1) != hash.end())
		{
			int start = nums[i] ;
			int val = hash[nums[i]+1]+1 ;
			int end = nums[i] + val -1 ;
			hash[start] = val ;
			hash[end] = val ;
		}
		else
		{
			hash[nums[i]] = 1 ;
		}
	}   
	map<int,int>::iterator it = hash.begin() ;   
	int max_ = 0 ; 
	for(; it != hash.end(); ++it)
	{
		if(it->second > max_)
			max_ = it->second ;
	}
	return max_ ;
}