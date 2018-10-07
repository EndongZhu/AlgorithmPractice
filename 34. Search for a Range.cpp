#include <vector>
#include <iostream>
using namespace std ;

vector<int> searchRange(vector<int>& nums, int target) 
{
	int len = nums.size() ;
	vector<int> ans ;
	ans.push_back(-1) ;
	ans.push_back(-1) ;

	if(len == 0)
		return ans ;
	
	int head = 0 , tail = len-1 ;
	while(head <= tail)
	{
		int mid = (head+tail)/2 ;
		if(nums[mid] == target)
		{
			int start = mid, end = mid ;
			while(nums[start] == nums[mid] && start >= 0)
			{
                --start ;
			}
			start += 1 ;
			while(nums[end] == nums[mid] && end < len)
			{
                ++end ;
			}
			end -= 1 ;
			ans[0] = start ;
			ans[1] = end ;
			break ;
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
	return ans ;
} 

int main()
{
	int myints[] = {5,7,7,8,8,10};
  	vector<int> numss (myints, myints + sizeof(myints) / sizeof(int) );
  	searchRange(numss,8) ;
}
