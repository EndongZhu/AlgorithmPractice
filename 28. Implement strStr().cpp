int strStr(string haystack, string needle) 
{
	int len1 = haystack.size() ;
	int len2 = needle.size() ;
	if(len2 > len1)
		return -1 ;

	for(int i = 0 ; i < len1-len2+1 ; i++)
	{
		string s1 = haystack.substr(i,len2) ;
		if(s1 == needle)
		{
			return i ;
		}
	}
	return -1 ;
}