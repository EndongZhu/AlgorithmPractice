bool isPalindrome(string s) 
{
	int size = s.size() ;
	char converted_str[size+1] = {0} ;
	int cnt = 0 ;
	for(int i = 0 ; i < size; i++)
	{
		if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
			converted_str[cnt++] = s[i] ;
		else if(s[i] >= 'A' && s[i] <= 'Z')
			converted_str[cnt++] = (char)(s[i]-('A'-'a')) ;
	}
	int len = cnt ;
	for(int i = 0 ; i < len/2 ; i++)
	{
		if(converted_str[i] != converted_str[len-1-i])
			return false ;
	}
	return true ;
}