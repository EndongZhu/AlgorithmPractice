vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> graph(numCourses, vector<int>());
    vector<int> degree(numCourses, 0);
    for(int i = 0; i < prerequisites.size(); i++) {
        int a = prerequisites[i].first;
        int b = prerequisites[i].second;
        graph[b].push_back(a);
        degree[a]++;
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
        if(degree[i] == 0)
            q.push(i);
    }
    vector<int> ans;
    int count = 0;
    while(!q.empty()) {
        int elem = q.front();
        q.pop();
        count++;
        ans.push_back(elem);
        for(int i = 0; i < graph[elem].size(); i++) {
            int next = graph[elem][i];
            if(--degree[i] == 0) {
                q.push(i);
            }
        }
        graph[elem] = vector<int>();
    }
    if(count != numCourses)
        return vector<int>();
    else
        return ans;
}
