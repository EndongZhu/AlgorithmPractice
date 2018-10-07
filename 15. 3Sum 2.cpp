#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std ;

vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(),nums.end()) ;
	int size = nums.size() ;
    vector<vector<int>> res ;
    if(size < 3)
    {
        return res ;
    }
    else if (nums[0] == nums[size-1])
    {
        if(nums[0] == 0)
        {
            vector<int> temp_ (3,0) ;
            res.push_back(temp_) ;
        }            
        return res ;
    }
	map<int, int> num_map ;
	for(int i = 0 ; i < size ; i++)
	{
		num_map[nums[i]] = i ;
	}
	for(int i = 0 ; i < size ; i++)
	{
		int target = -nums[i] ;
		for(int j = i+1 ; j < size ; j++)
		{
			if(nums[j] == nums[j-1])
				continue ;
			int comp = target - nums[j] ;
			it = num_map.find(comp) ;
			if(it != num_map.end() && it->second > j)
			{
				vector<int> temp ;
				temp.push_back(nums[i]) ;
				temp.push_back(nums[j]) ;
				temp.push_back(nums[it->second]) ;
                res.push_back(tmp) ;
			}
		}
	}
	return res ;
}