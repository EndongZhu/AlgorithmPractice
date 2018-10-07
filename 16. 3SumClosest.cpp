int threeSumClosest(vector<int>& nums, int target) {
	sort(nums.begin(),nums.end()) ;
	int size = nums.size() ;
    if(size < 3)	return NULL ;

    int closest = INT_MAX ;
    for(int i = 0 ; i < size ; i++)
    {
    	int a = i+1 , b = size-1 ;
    	while(a < b)
    	{
    		sum = nums[i] + nums[a] + nums[b] ;
    		if (abs(sum-target) < closest)
    		{
    			closest = abs(sum-target) ;
    		}
    		if(sum == target)
    			return 0 ;
    		else if (sum > target)
    			b-- ;
    		else
    			a++ ;
    	}
    }
    return closest ;
}