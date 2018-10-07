#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std ;

vector<string> letterCombinations(string digits) {
	string dig2ch[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} ;
	queue<string> que ;
	que.push("") ;
    vector<string> ans ;
	int len = digits.size() ;
    if(len == 0) 
        return ans ;
	for(int i = 0 ; i < len ; i++)
	{
		string candidate = dig2ch[digits[i]-'0'] ;
		int que_len = que.size() ;
		for(int j = 0 ; j < que_len ; j++)
		{
			string elem = que.front() ;
			que.pop() ;
			for(int k = 0; k < candidate.size() ; k++)
			{
				string new_elem = elem + candidate[k] ;
				que.push(new_elem) ;
			}
		}
	}
	int ans_len = que.size() ;
	for (int i = 0 ; i < ans_len ; i++)
	{
		ans.push_back(que.front()) ;
		que.pop() ;
	}
	return ans ;
}

int main()
{
	string input ;
	cin >> input ;
	vector<string> res = letterCombinations(input) ;
	for(int i = 0 ; i < res.size() ; i++)
	{
		cout << res[i] << endl ;
	}
}
