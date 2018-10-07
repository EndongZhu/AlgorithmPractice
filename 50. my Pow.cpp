double myPow(double x, int n) 
{
	if(n == 0)
		return 1 ;
	else if(n == 1)
		return x ;
	else if(n > 0)
	{
		int mod = n%2 ;
		double num = myPow(x,n/2) ;
		return num*num*myPow(x,mod) ;
	}        
	else
	{
		if(n == INT_MIN)
			n = INT_MAX-1 ;
		else
			n = -n ;
		x = 1.0/x ;
		int mod = n%2 ;
		double num = myPow(x,n/2) ;
		return num*num*myPow(x,mod) ;
	}
}