void permutation(vector<int>& res, int depth, int cur, vector<int>& elem) {
    if(depth == 4) {
        if(cur/100 < 24 && cur % 100 < 60 && (res.size() == 0 ||find(res.begin(),res.end(),cur) == res.end()))
            res.push_back(cur) ;
        return ;
    }

    for(int i = 0; i < elem.size(); i++) {
        int new_num = cur*10 + elem[i] ;
        permutation(res, depth+1, new_num, elem) ;
    }
}

string int2str(int num) {
    if(num == 0)
        return "0" ;
    string ans = "" ;
    while(num) {
        ans = (char)('0'+num%10) + ans ;
        num = num/10 ;
    }
    return ans ;
}

string nextClosestTime(string time) {
    vector<int> elem ;
    int target = 0 ;
    for(int i = 0; i < time.size(); i++) {
        if(time[i] >= '0' && time[i] <= '9') {
            target = target*10 + (time[i]-'0') ;
            elem.push_back(time[i]-'0') ;
        }
    }
    vector<int> res ;
    permutation(res, 0, 0, elem) ;
    sort(res.begin(),res.end()) ;
    int pos = 0 ;
    for(int i = 0 ; i < res.size(); i++) {
        if(res[i] == target) {
            pos = i ;
        }
    }
    int next = (pos+1)%res.size() ;
    int ans_num = res[next] ;
    int hour_num = ans_num/100 ;
    int min_num = ans_num%100 ;
    string hour = "" ;
    hour = hour_num < 10 ? "0"+int2str(hour_num) : int2str(hour_num) ;
    string min = "" ;
    min = min_num < 10 ? "0"+int2str(min_num) : int2str(min_num) ;

    return hour+":"+min ;
}
