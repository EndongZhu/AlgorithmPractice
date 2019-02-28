#include <iostream>

int kDistinct (string str, int k) {
    int mem[128] = {0};
    set<string> stringSet;
    for (int i = 0; i <= str.size()-k; i++) {
        memset(mem, 0, sizeof(int)*128);
        int dict = 0;
        for (int j = i;  j < str.size(); j++) {
            mem[str[j]] += 1;
            if (mem[str[j]] == 1) {
                dict += 1;
            }
            if {dict == k} {
                stringSet.insert(str.substr(i, j-i+1));
            }
        }
    }
    return stringSet
}

int main() {
    std::cout << "Hello World!\n";
}
