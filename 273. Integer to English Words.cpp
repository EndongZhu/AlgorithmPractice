string ones[10] = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
string tens_small[10] = {"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen",
                        "Sixteen","Seventeen","Eighteen","Nineteen"};
string tens[10] = {"","","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy "
                    ,"Eighty ","Ninety "};
string depths[3] = {"Thousand ","Million ","Billion "};

string numberToWords(int num) {
    if(num == 0)
        return "Zero" ;
    string ans = "" ;
    converter(num, 0, ans) ;
    if(ans[ans.size()-1] == ' ')
        ans.erase(ans.end()-1) ;
    return ans ;
}

void converter(int num, int depth, string& ans) {
    int hi_digits = num / 1000 ;
    int lo_digits = num % 1000 ;
    if(lo_digits != 0) {
        int hund = lo_digits / 100 ;
        int ten = (lo_digits % 100) / 10 ;
        int one = (lo_digits % 100) % 10 ;
        if(ten == 1) {
            ans = tens_small[one] + " " + ans ;
            if(hund != 0)
                ans = ones[hund] + "Hundred " + ans ;
        }
        else {
            ans = ones[one] + ans ;
            ans = tens[ten] + ans ;
            if(hund != 0)
                ans = ones[hund] + "Hundred " + ans ;
        }
    }
    if(hi_digits != 0) {
        if(hi_digits % 1000 != 0)
            ans = depths[depth] + ans ;
        converter(hi_digits, depth+1, ans) ;
    }
}
