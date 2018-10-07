#include <iostream>
#include <string>
using namespace std ;

string intToRoman(int num) {

	string tho[] = {"","M","MM","MMM"} ;
	string hun[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"} ;
	string ten[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"} ;
	string uni[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"} ;
	
    string ans = "" ;
    int num0 = num ;
    int a = num0/1000 ;
    num0 = num0 - a*1000 ;
    int b = num0/100 ;
    num0 = num0 - b*100 ;
    int c = num0/10 ;
    num0 = num0 - c*10 ;
    int d = num0 ;

    ans = tho[a] + hun[b] + ten[c] + uni[d] ;
    return ans ;
}

int main()
{
	int test  ;
	cin >> test ;
	cout << intToRoman(test) << endl ;
}