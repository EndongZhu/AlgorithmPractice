#include <iostream>
#include <string>
#include <vector>
using namespace std ;

string longestCommonPrefix(vector<string>& strs) 
{
	int size = strs.size() ;
	if(size<=0)
		return "" ;
	
    int pos = -1 ;
    bool flag = 1 ;
    while(flag)
    {
    	pos++ ;
    	for(int i = 0 ; i < strs.size() ; i++)
    	{
    		if(strs[i].size() == 0)
    			return "" ;
    		else if(strs[i].size()<=pos)
			{
				flag = 0 ;
				break ;
			}	
			else if(strs[i][pos] != strs[0][pos])
			{
				flag = 0 ;
				break ;
			}
    	}
    }
    
    string ans = strs[0].substr(0,pos) ;
    return ans ;
}
