static bool a_less_b(const Interval& a,const Interval& b)  
{  
    return a.start < b.start ;  
} 

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) 
{
	intervals.push_back(newInterval) ;
	sort(intervals.begin(), intervals.end(), a_less_b) ;

	vector<Interval> res ;
	res.push_back(intervals[0]) ;
	int len = intervals.size() ;
	for(int i = 1 ; i < len ; i++)
	{
		Interval cur = intervals[i] ;
		if(res.back().end >= cur.start)
		{
			res.back().end = max(res.back().end,cur.end) ;
		}
		else
		{
			res.push_back(cur) ;
		}
	}

	return res ;
}