#include <iostream>
#include <string>
using namespace std ;

int romanToInt(string s) {

	string tho[] = {"","M","MM","MMM"} ;
	string hun[] = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"} ;
	string ten[] = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"} ;
	string uni[] = {"","I","II","III","IV","V","VI","VII","VIII","IX"} ;
	
    int pos1 = 0 ;
    int pos2 = 0 ;
    while(s[pos2] == 'M') pos2++ ;
    string tho_roman = s.substr(pos1,pos2-pos1) ;
    int ind = 0 ;
    while(tho[ind]!=tho_roman)	ind++ ;
    int tho_num = ind ;
    
    pos1 = pos2 ;
    while(s[pos2] == 'C' || s[pos2] == 'D' || s[pos2] == 'M')	pos2++ ;
    string hun_roman = s.substr(pos1,pos2-pos1) ;
    ind = 0 ;
    while(hun[ind]!=hun_roman)	ind++ ;
    int hun_num = ind ;
    
    pos1 = pos2 ;
    while(s[pos2] == 'X' || s[pos2] == 'L' || s[pos2] == 'C')	pos2++ ;
    string ten_roman = s.substr(pos1,pos2-pos1) ;
    ind = 0 ;
    while(ten[ind]!=ten_roman)	ind++ ;
    int ten_num = ind ;
    
    pos1 = pos2 ;
    while(s[pos2] == 'I' || s[pos2] == 'V' || s[pos2] == 'X')	pos2++ ;
    string uni_roman = s.substr(pos1,pos2-pos1) ;
    ind = 0 ;
    while(uni[ind]!=uni_roman)	ind++ ;
    int uni_num = ind ;
    
    int ans = tho_num*1000 + hun_num*100 + ten_num*10 + uni_num*1 ;
    return ans ;
}

int main()
{
	string test  ;
	cin >> test ;
	cout << romanToInt(test) << endl ;
}
