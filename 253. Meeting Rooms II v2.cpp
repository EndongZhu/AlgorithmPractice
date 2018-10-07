int minMeetingRooms(vector<Interval>& intervals) {
    int len = intervals.size() ;
    if(len <= 1)
        return len ;
    int start_arr[len] = {0} ;
    int end_arr[len] = {0} ;
    for(int i = 0; i < len; i++) {
        start_arr[i] = intervals[i].start ;
        end_arr[i] = intervals[i].end ;
    }
    sort(start_arr, start_arr+len) ;
    sort(end_arr, end_arr+len) ;
    int start_pos = 0 ;
    int end_pos = 0 ;
    int used_room = 0 ;
    while(start_pos < len) {
        if(start_arr[start_pos] >= end_arr[end_pos]) {
            ++end_pos ;
        }
        else {
            ++used_room ;
        }
        ++start_pos ;
    }
    return used_room ;
}
