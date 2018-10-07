struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

static bool a_less_b(const Interval& a,const Interval& b)  
{  
    return a.start < b.start ;  
} 

vector<Interval> merge(vector<Interval>& intervals) 
{
	sort(intervals.begin(), intervals.end(), a_less_b) ;

	int len = intervals.size() ;
	for(int i = 1 ; i < len ; i++)
	{
		Interval last = intervals[i-1] ;
		Interval cur = intervals[i] ;
		if(last.end >= cur.start)
		{
			intervals[i-1].end = max(intervals[i-1].end,intervals[i].end) ;
			intervals.erase(i) ;
			i-- ;
		}
	}

	return intervals ;
}