string addBinary(string a, string b) 
{
	int len1 = a.size() ;
	int len2 = b.size() ;
	int pos1 = len1-1 ;
	int pos2 = len2-1 ;

	int carrier = 0 ;
	string ans = "" ;
	while(pos1>=0 || pos2>=0)
	{
		int res = carrier + (a[pos1]-'0') + (b[pos2]-'0') ;
		carrier = res/2 ;
		res = res%2 ;
		if(res)
			ans = "1" + ans ;
		else
			ans = "0" + ans ;
		
		if(pos1 > 0)	
			pos1-- ;
		else
			a[pos1] = '0' ;

		if(pos2 > 0)
			pos2-- ;
		else
			b[pos2] = '0' ;
	}        

	if(carrier)
		ans = "1" + ans ;

	return ans ;
}