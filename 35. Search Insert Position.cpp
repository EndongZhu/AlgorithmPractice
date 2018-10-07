#include <vector>
#include <iostream>
using namespace std ;

int searchInsert(vector<int>& nums, int target) 
{
	int len = nums.size() ;
	if(len == 0)
		return -1 ;
	
	int head = 0 , tail = len-1 ;
	while(head < tail)
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
	if(nums[head] >= target)
		return head ;
	else
		return head+1 ;
}

int main()
{
	int myints[] = {1,3,5,6};
  	vector<int> numss (myints, myints + sizeof(myints) / sizeof(int) );
  	cout << searchInsert(numss,7) << endl ;
}
