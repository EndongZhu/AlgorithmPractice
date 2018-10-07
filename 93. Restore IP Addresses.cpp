#include <iostream>
#include <vector>
#include <string>
using namespace std ;

void dfs(vector<string> &ans, string s, int pos, int cur)
{
	if(cur == 3)
	{
		int num = stoi(s.substr(pos)) ;
		if(num >= 0 && num <= 255)
			ans.push_back(s) ;
	}
	else
	{
		for(int i = pos; i < pos+3 && i < s.size(); i++)
		{
			int num = stoi(s.substr(pos,i-pos+1)) ;
			if(num >= 0 && num <= 255)
			{
				string s_new = s ;
				s_new.insert(s_new.begin()+i+1,'.') ;
				dfs(ans,s_new,i+2,cur+1) ;
			}	
		}
	}
}

vector<string> restoreIpAddresses(string s) 
{
	vector<string> res; 
	dfs(res,s,0,0) ;
	return res ;
}

int main()
{
	string s ;
	cin >> s ;
	vector<string> res = restoreIpAddresses(s) ;
	for(int i = 0 ; i < res.size() ; i++)
	{
		cout << res[i] << endl ;
	}
}
