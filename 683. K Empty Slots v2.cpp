int kEmptySlots(vector<int>& flowers, int k) {
    int len = flowers.size() ;
    if(len <= 1)
        return -1 ;
    int days[len+1] = {0} ;
    for(int i = 0; i < len; i++) {
        days[flowers[i]] = i+1 ;
    }
    int left = 1, right = left+k+1 ;
    int ans = INT_MAX ;
    for(int i = 2; i <= len && right <= len; i++) {
        if(i == right)
            ans = min(ans, max(days[left],days[right])) ;
        if(days[i] < days[left] || days[i] < days[right]){
            left = i ;
            right = left+k+1 ;
        }
    }
    return ans == INT_MAX ? -1 : ans ;
}
