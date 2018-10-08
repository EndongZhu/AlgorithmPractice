vector<int> graph[numCourses] ;
bool used[numCourses] ;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    for(int i = 0; i < prerequisites.size(); i++) {
        int a = prerequisites[i].first;
        int b = prerequisites[i].second;
        graph[a].push_back(b);
    }
    for(int i = 0; i < numCourses; i++) {
        if(used[i])
            continue;
        unordered_set<int> visited;
        if(!dfs(i, visited))
            return false;
    }
    return true;
}

bool dfs(int node, unordered_set<int>& visited) {
    if(visited.find(node) != visited.end())
        return false;
    visited.push(node);
    used[node] = 1;
    for(int i = 0; i < graph[node].size(); i++) {
        int next = graph[node][i];
        if(!dfs(next, visited))
            return false;
    }
    return true;
}
