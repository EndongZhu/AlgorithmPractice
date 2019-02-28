int calculate(string expr) {
    long cur = 0;
    long prev = 0;
    bool first = 1;
    for(int i = 0; i < expr.size();) {
        if(first) {
            int start = 0;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && i < expr.size())
                ++i;
            cur = stol(expr.substr(start, i), nullptr, 10);
            prev = cur;
            first = 0;
        }
        else if(expr[i] == '+') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && i < expr.size())
                ++i;
            prev = stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur + prev;
        }
        else if(expr[i] == '-') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && i < expr.size())
                ++i;
            prev = -stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur + prev ;
        }
        else if(expr[i] == '*') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && i < expr.size())
                ++i;
            int temp = stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur - prev + temp*prev;
            prev = temp*prev;
        }
        else if(expr[i] == '/') {
            int start = ++i;
            while(expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/' && i < expr.size())
                ++i;
            int temp = stol(expr.substr(start, i-start), nullptr, 10);
            cur = cur - prev + prev/temp;
            prev = prev/temp;
        }
    }
    return cur;
}
