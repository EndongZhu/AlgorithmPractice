static bool cmp(Interval& a, Interval& b) {
    return a.start < b.start ;
}

bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp) ;
    int len = intervals.size() ;
    if(len <= 1)
        return true ;
    for(int i = 1; i < len; i++) {
        if(intervals[i].start < intervals[i-1].end)
            return false ;
    }
    return true ;
}
