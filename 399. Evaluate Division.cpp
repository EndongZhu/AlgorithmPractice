class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i].first;
            string b = equations[i].second;
            if (mem.find(a) != mem.end()) {
                mem[a].push_back(make_pair(b, values[i]));
            } else {
                vector<pair<string,double>> temp;
                temp.push_back(make_pair(b, values[i]));
                mem[a] = temp;
            }
            if (mem.find(b) != mem.end()) {
                mem[b].push_back(make_pair(a, 1.0 / values[i]));
            } else {
                vector<pair<string,double>> temp;
                temp.push_back(make_pair(a, 1.0 / values[i]));
                mem[b] = temp;
            }
        }
        vector<double> ans;
        for (auto query : queries) {
            ans.push_back(bfs(query.first, query.second));
        }
        return ans;
    }

    double bfs(string origin, string target) {
        if (mem.find(origin) == mem.end() || mem.find(target) == mem.end()) {
            return -1.0;
        }
        unordered_set<string> visited;
        queue<pair<string, double>> que;
        que.push(make_pair(origin, 1.0));
        while(!que.empty()) {
            string cur = que.front().first;
            double prod = que.front().second;
            que.pop();
            visited.insert(cur);
            if (cur == target) {
                return prod;
            }
            for(int i = 0; i < mem[cur].size(); i++) {
                pair<string,double> elem = mem[cur][i];
                if (visited.find(elem.first) == visited.end()) {
                    string new_s = elem.first;
                    double new_prod = prod * elem.second;
                    que.push(make_pair(new_s, new_prod));
                }
            }
        }
        return -1.0;
    }

private:
    unordered_map<string, vector<pair<string,double>>> mem;
};
