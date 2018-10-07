int leastInterval(vector<char>& tasks, int n) {
    map<char, int> mem ;
    map<char, int> scheduler ;
    vector<char> name ;
    for(int i = 0; i < tasks.size(); i++) {
        if(mem.find(tasks[i]) == mem.end()) {
            name.push_back(tasks[i]) ;
            mem[tasks[i]] = 1 ;
            scheduler[tasks[i]] = 0 ;
        }
        else {
            mem[tasks[i]] += 1 ;
        }
    }
    int t = 0 ;
    int cnt = 0 ;
    while(!name.empty()) {
        int max_num = -1 ;
        int max_pos = -1 ;
        for(int i = 0; i < name.size(); i++) {
            if(scheduler[name[i]] <= t && mem[name[i]] > max_num) {
                max_num = mem[name[i]] ;
                max_pos = i ;
            }
        }
        if(max_pos >= 0) {
            scheduler[name[max_pos]] = t+1+n ;
            if(--mem[name[max_pos]] <= 0)
                name.erase(name.begin()+max_pos) ;
        }
        ++t ;
    }
    return t ;
}
