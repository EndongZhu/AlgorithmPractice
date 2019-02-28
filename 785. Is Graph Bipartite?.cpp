bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    if(n <= 1)
        return false;

    unordered_map<int, int> mem;
    queue<int> que;
    for(int node = 0; node < n; node++)
    {
        if(mem.find(node) != mem.end())
            continue;
        que.push(i);
        mem[i] = 0;
        while(!que.empty()) {
            int cur = que.front();
            que.pop();
            for(int i = 0; i < graph[cur].size(); i++) {
                int neighbor = graph[cur][i];
                if(mem.find(neighbor) == mem.end()) {
                    mem[neighbor] ^= 1;
                    que.push(neighbor);
                }
                else if(mem[neighbor] == mem[cur]) {
                    return false;
                }
            }
        }
    }
    return true;
}
