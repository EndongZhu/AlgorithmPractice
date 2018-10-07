int trap(vector<int>& height) 
{
	int len = height.size() ;
	vector<int>  flag ;
	if(len <= 2)
		return 0 ;
	if(height[0] > height[1])
		flag.push_back(0) ;
	for(int i = 1 ; i < len-1 ; i++)
	{
		if(height[i] > height[i-1] && height[i] > height[i+1])
			flag.push_back(i) ;
	}
	if(height[len-1] > height[len-2])
		flag.push_back(len-1) ;

	int flag_len = flag.size() ;
	if(flag_len < 2)
		return 0 ;
	while(flag.size()>2)
	{
		flag_len = flag.size() ;
		bool judge = 0 ;
		for(int i = 1 ; i < flag_len-1 ; i++)
		{
			int a = flag[i-1] , b = flag[i] , c = flag[i+1] ;
			if(height[a] > height[b] && height[b] < height[c])
			{
				flag.erase(flag.begin()+i) ;
				judge = 1 ;
				break ;
			}
		}
		if(!judge)
			break ;
	}
	flag_len = flag.size() ;
	int sum = 0 ;
	for(int i = 0 ; i < flag_len-1 ; i++)
	{
		int a = flag[i] , b = flag[i+1] ;
		int num = compute(height, a , b) ;
		sum += num ;
	}
	return sum ;
}

int compute(vector<int>& height, int pos1 , int pos2)
{
	int h = min(height[pos1],height[pos2]) ;
	int sum = 0 ;
	for(int i = pos1+1 ; i < pos2 ; i++)
	{
		sum += h-height[i] ;
	}
	return sum ;
}