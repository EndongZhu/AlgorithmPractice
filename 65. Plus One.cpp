vector<int> plusOne(vector<int>& digits) 
{
	int len = digits.size() ;

	digits[len-1] += 1 ;
	int pos = len-1 ;
	while(digits[pos] >= 10 && pos >= 1)
	{
		digits[pos] %= 10 ;
		digits[pos-1] += 1 ;
		pos-- ;
	}        
	if(digits[0] >= 10)
	{
		digits[0] %= 10 ;
		it = digits.begin() ;
		digits.insert(it, 1) ;
	}

	return digits
}