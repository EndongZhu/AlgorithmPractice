int largestRectangleArea(vector<int>& heights) 
{
	int len = heights.size() ;
	heights.push_back(0) ;
	stack<int> st ;
	int ans = 0 ;
	for(int i = 0 ; i < n ; i++)
	{
		while(!st.empty() && heights[i] <= heights[st.top()])
		{
			int idx = st.top() ;
			st.pop() ;
			int left = st.empty()?-1:st.top() ;
			int num = heights[idx]*(i-left-1) ;
			ans = max(ans,num) ;
		}
		st.push_back(i) ;
	}
	return ans ;
}