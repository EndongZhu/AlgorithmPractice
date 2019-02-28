int maxChunksToSorted(vector<int>& arr) {
        unordered_map<int, int> mem;
        vector<int> expect(arr);
        sort(expect.begin(), expect.end());
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < arr.size(); i++) {
            mem[arr[i]] = mem.find(arr[i]) == mem.end() ? 1 : mem[arr[i]]+1;
            if(mem[arr[i]] == 0)
                cnt--;
            else if(mem[arr[i]] == 1)
                cnt++;
            mem[expect[i]] = mem.find(expect[i]) == mem.end() ? -1 : mem[expect[i]]-1;
            if(mem[expect[i]] == 0)
                cnt--;
            else if(mem[expect[i]] == -1)
                cnt++;
            if(cnt == 0)
                ans++;
        }
        return ans;
}
