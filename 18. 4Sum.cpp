#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std ;

vector< vector<int> > fourSum(vector<int>& nums, int target) 
{
	sort(nums.begin(),nums.end()) ;
	int size = nums.size() ;
    vector< vector<int> > res ;
    if(size < 4)
        return res ;

    for(int a = 0 ; a < size-3 ; a++)
    {
    	for(int b = a+1 ; b < size-2 ; b++)
    	{
    		int c = b+1 , d = size-1 ;
    		while(c < d)
    		{
    			int sum = nums[a] + nums[b] + nums[c] + nums[d] ;
    			if(sum == target)
    			{
    				vector<int> v_temp ;
                    v_temp.push_back(nums[a]) ;
                    v_temp.push_back(nums[b]) ;
                    v_temp.push_back(nums[c]) ;
                    v_temp.push_back(nums[d]) ;
    				res.push_back(v_temp) ;
    				break ;
    			}
    			else if(sum > target)
    			{
    				d-- ;
    			}
    			else
    			{
    				c++ ;
    			}
    		}
    	}
    }

    return res ;
}

int main()
{
	int input[] = {1,0,-1,0,-2,2} ;
	vector<int> input_vec (input , input+sizeof(input) / sizeof(int)) ;
	fourSum(input_vec, 0) ;
}
