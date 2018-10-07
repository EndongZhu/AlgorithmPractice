#include <iostream>
#include <algorithm>
using namespace std ;

int divide(int dividend, int divisor) 
{
	if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
		return INT_MAX ;
	if(dividend == 0)
		return 0 ;

	bool sig = (dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0) ;

	long long dvd = dividend ;
	dvd = abs(dvd) ;
	long long dvs = divisor ;
	dvs = abs(dvs) ;

	long long res = 0 ;
	while(dvd >= dvs)
	{
		long long tmp = dvs ; long long multiple = 1;
		while(dvd >= tmp)
		{
			tmp <<= 1 ;
			multiple <<= 1 ;
		}
		tmp >>= 1 ;
		multiple >>= 1 ;
		res += multiple ;
		dvd -= tmp ;
	}

	if(sig)	res = -res ;
	return res ;
}

int main()
{
	int a, b ;
	cin >> a >> b ;
	cout << divide(a,b) << endl ;
}
