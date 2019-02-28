#include <iostream>
#include <set>
#include <cstdlib>

vector<string> stringDistinct(string str, int k) {
    vector<string> ans;
    if (k > str.size())
        return ans;
    int mem[128] = {0};
    set<string> stringSet;
    memset(mem, 0, sizeof(int)*128);
    int dict = 0;
    for(int i = 0; i < k; i++) {
        int idx = (int) str[i];
        mem[idx] += 1;
        if (mem[idx] == 1) {
            dict += 1;
        }
    }
    if (dict == k-1) {
        stringSet.insert(str.substr(0, k));
    }
    int left = 0;
    int right = k-1;
    while (right < str.size()) {
        mem[str[left]]--;
        if (mem[str[left]] == 0) {
            dict--;
        }
        left++;
        right++;
        mem[str[right]]++;
        if(mem[str[right]] == 1) {
            dict++;
        }
        if (dict == k-1) {
            stringSet.insert(str.substr(left, right-left+1));
        }
    }
    for (auto s : stringSet) {
        ans.push_back(s);
    }
    return ans;
}


int main() {
    vector<string> res = stringDistinct("abcdaabcda",  5);
    for (auto s : res) {
        cout << s << endl;
    }
}
