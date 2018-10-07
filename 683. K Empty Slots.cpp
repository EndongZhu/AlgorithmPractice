int kEmptySlots(vector<int>& flowers, int k) {
    int len = flowers.size() ;
    bool bloom[len+1] = {0} ;
    for(int i = 0; i < len; i++) {
        int pos = flowers[i] ;
        bloom[pos] = 1 ;
        if(pos-(k+1) > 0) {
            bool flag = 1 ;
            for(int j = pos-1; j > pos-(k+1); j--) {
                if(bloom[j])
                    flag = 0 ;
            }
            if(flag && bloom[pos-k-1])
                return i+1 ;
        }
        else if(pos+(k+1) <= len) {
            bool flag = 1 ;
            for(int j = pos+1; j < pos+(k+1); j++) {
                if(bloom[j])
                    flag = 0 ;
            }
            if(flag && bloom[k+pos+1])
                return i+1 ;
        }
    }
    return -1 ;
}
