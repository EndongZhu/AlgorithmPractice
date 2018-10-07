bool isValid(string s) 
{
	stack<char> st ;
	for(int i = 0 ; i < s.size() ; i++)
	{
		if(s[i] == '(')
			st.push(')') ;
		else if(s[i] == '[')
			st.push(']') ;
		else if(s[i] == '{')
			st.push('}') ;
		else if(s[i] == ')' || s[i] == ']' || s[i] == '}')
		{
			if(st.empty())
				return false ;
			char elem = st.top() ;
			st.pop() ;
			if(s[i] != elem)
				return false ;
		}
	}        
	return true ;
}