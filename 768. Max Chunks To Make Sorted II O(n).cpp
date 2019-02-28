int maxChunksToSorted(vector<int>& arr) {
    int len = arr.size();

    int max_mem[len] = {0};
    int max_elem = INT_MIN;
    for(int i = 0; i < len; i++) {
        if(arr[i] > max_elem)
            max_elem = arr[i];
        max_mem[i] = max_elem;
    }
    int min_elem = INT_MAX;
    int ans = 1;
    for(int i = len-1; i >= 1; i--) {
        if(arr[i] < min_elem) {
            min_elem = arr[i];
        }
        if(min_elem >= max_mem[i-1])
            ans++;
    }
    return ans;
}
