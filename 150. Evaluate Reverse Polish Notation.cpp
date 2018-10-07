int str2int(string str) {
    bool is_neg = 0 ;
    if(str[0] == '-') {
        is_neg = 1 ;
        str = str.substr(1) ;
    }
    int len = str.size() ;
    int res = 0 ;
    for(int i = 0; i < len; i++) {
        res = res*10 + (str[i]-'0') ;
    }
    return is_neg ? -res : res ;
}

int compute(int num1, int num2, string oper) {
    if(oper == "+") {
        return num1 + num2 ;
    }
    else if(oper == "-") {
        return num2 - num1 ;
    }
    else if(oper == "*") { 
        return num1 * num2 ;
    }
    else {
        return num2 / num1 ;
    }
}

int evalRPN(vector<string>& tokens) {
    stack <int> st ;
    int size = tokens.size() ;
    if(size == 0)
        return 0 ;
    else if(size == 1)
        return str2int(tokens[0]) ;

    st.push(str2int(tokens[0])) ;
    st.push(str2int(tokens[1])) ;
    for(int i = 2 ; i < size ; i++) {
        if (tokens[i] == "+" ||
            tokens[i] == "-" ||
            tokens[i] == "*" ||
            tokens[i] == "/") {
                int num1 = st.top() ;
                st.pop() ;
                int num2 = st.top() ;
                st.pop() ;
                int res = compute(num1, num2, tokens[i]) ;
                st.push(res) ;
            }
        else {
            int num = str2int(tokens[i]) ;
            st.push(num) ;
        }
    }
    int ans = st.top() ;
    st.pop() ;
    return ans ;
}
