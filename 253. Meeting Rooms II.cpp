static bool cmp(Interval& a, Interval& b) {
    return a.start < b.start ;
}

int minMeetingRooms(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp) ;
    int len = intervals.size() ;
    if(len <= 1)
        return len ;
    priority_queue<int, vector<int>, greater<int>> rooms ;
    rooms.push(intervals[0].end) ;
    for(int i = 1; i < len; i++) {
        if(intervals[i].start < rooms.top()) {
            rooms.push(intervals[i].end) ;
        }
        else {
            rooms.pop() ;
            rooms.push(intervals[i].end) ;
        }
    }
    return rooms.size() ;
}
