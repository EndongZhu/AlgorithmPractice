#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std ;

vector<string> generateParenthesis(int n) 
{	
	vector<string> ans ;
	if(n == 0)
		return ans ;
	queue<string> que ;
	que.push("") ;
	for(int i = 0 ; i < n ; i++)
	{
		int que_size = que.size() ;
		for(int j = 0 ; j < que_size ; j++)
		{
			string elem = que.front() ;
			que.pop() ;
			int elem_size = elem.size() ;
			for(int k = 0 ; k <= 2*i-elem_size+1 ; k++)
			{
				string comp(k,')') ;
				comp = "("+comp ;
				que.push(elem+comp) ;
			}
		}
	}
	int fin_size = que.size() ;
	for(int i = 0 ; i < fin_size ; i++)
	{
		string elem = que.front() ;
		que.pop() ;
		int elem_size = elem.size() ;
		if(elem_size < 2*n) 
		{
			for(int k = 0 ; k < 2*n-elem_size ; k++)
			{
				elem = elem+")" ;
			}
		}
		if(find(ans.begin(),ans.end(),elem) == ans.end())
			ans.push_back(elem) ;
	}

	return ans ;
}

int main()
{
	int n ; 
	cin >> n ;
	vector<string> vec = generateParenthesis(n) ;
	for(int i = 0 ; i < vec.size() ; i++)
	{
		cout << vec[i] << endl ;
	}
}
