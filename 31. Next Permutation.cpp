#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

void nextPermutation(vector<int>& nums) 
{
	int len = nums.size() ;
	for(int i = len-1 ; i >= 0; i--)
	{
        int cnt = INT_MAX ;
		int pos1 = -1 , pos2 = -1 ;
		for(int j = i+1 ; j < len ; j++)
		{
			if(nums[j] > nums[i] && nums[j]-nums[i] < cnt)
			{
				cnt = nums[j] - nums[i] ;
				pos1 = i ;
				pos2 = j ;
			}
		}
        if(pos1 != -1 && pos2 != -1)
        {
        	int a = nums[pos1], b = nums[pos2] ;
            swap(nums[pos1],nums[pos2]) ;
            a = nums[pos1], b = nums[pos2] ;
            sort(nums.begin()+pos2, nums.end()) ;
            return ;
        }
	}
	sort(nums.begin(),nums.end()) ;
	return ;
}

int main()
{
	vector<int> num ;
	num.push_back(2) ;
	num.push_back(3) ;
	num.push_back(1) ;
	nextPermutation(num) ;
	for(int i = 0 ; i < 3 ; i++)
	{
		cout << num[i] << " " ;
	}
	cout << endl ;
}
