#include <string>
#include <vector>
#include <iostream>
using namespace std ;

int numDecodings(string s) 
{
	int len = s.size() ;

	int dp[10001] = {0} ;
	dp[0] = 1 ;
	dp[1] = 1 ;
	for(int i = 2 ; i <= len ; i++)
	{
		int num1 = s[i-1]-'0' ;
		int num2 = (s[i-2]-'0')*10 + s[i-1]-'0' ;
		if(num1 >= 1 && num1 <= 26)
		{
			dp[i] += dp[i-1] ;
		}
		if(num2 >= 1 && num2 <= 26)
		{
			dp[i] += dp[i-2] ;
		}
	}
	return dp[len] ;
}

int main()
{
	string s ;
	cin >> s ;
	cout << numDecodings(s) << endl ;
}
