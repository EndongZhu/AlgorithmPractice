vector<string> addOperators(string num, int target) {
    vector<string> ans;
    if(num.size() == 0)
        return ans;

    vector<string> perm;
    permutation(perm, num, 1);
    cout << perm[1] << endl;
    cout << cal(perm[1]) << endl;
}

void permutation(vector<string>& perm, string s, int pos) {
    if(pos >= s.size()) {
        perm.push_back(s);
        return;
    }
    permutation(perm, s, pos+1);
    string s_1 = s; s_1.insert(s_1.begin()+pos, '+');
    permutation(perm, s_1, pos+2);
    string s_2 = s; s_2.insert(s_2.begin()+pos, '-');
    permutation(perm, s_2, pos+2);
    string s_3 = s; s_3.insert(s_3.begin()+pos, '*');
    permutation(perm, s_3, pos+2);
}

int cal(string expr) {
    int cur = 0;
    int prev = 0;
    bool first = 1;
    for(int i = 0; i < expr.size()) {
        if(first) {
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && i < expr.size())
                ++i;
            cur += stol(expr.substr(0, i), nullptr, 10);
        }
        else if(expr[i] == '+') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && i < expr.size())
                ++i;
            prev = stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur + prev;
        }
        else if(expr[i] == '-') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && i < expr.size())
                ++i;
            prev = -stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur + prev ;
        }
        else if(expr[i] == '*') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && i < expr.size())
                ++i;
            int temp = stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur - prev + temp*prev;
            prev = remp*prev;
        }
    }
    return cur;
}
