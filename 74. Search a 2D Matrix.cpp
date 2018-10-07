bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
	int len = matrix.size() ;

	int lower_bound = 0 ;
	int upper_bound = len ;

	while(lower_bound < upper_bound)
	{
		int mid = (lower_bound+upper_bound)/2 ;

		if(lower_bound = upper_bound-1)
		{
			if(target >= matrix[upper_bound][0])
				lower_bound = upper_bound ;
			else
				upper_bound = lower_bound ;
		}
		else if(target > matrix[mid][0])
		{
			lower_bound = mid ;
		}
		else
		{
			upper_bound = mid ;
		}
	}

	int pos = lower_bound ;
	int lower_bound_2 = 0 ; 
	int upper_bound_2 = matrix[pos].size()-1 ;
	while(lower_bound_2 <= upper_bound_2)
	{
		int mid = (lower_bound_2+upper_bound_2)/2 ;
		if(target == matrix[pos][mid])
			return true ;
		else if(target > matrix[pos][mid])
		{
			lower_bound_2 = mid+1 ;
		}
		else
		{
			upper_bound_2 = mid-1 ;
		}
	}

	return false ;
}

int main()
{
	vector<vector<int>> test ;
	vector<int> v1 ; v1.push_back(1); v1.push_back(3); v1.push_back(5); v1.push_back(7);
	vector<int> v2 ; v2.push_back(10); v2.push_back(11); v2.push_back(16); v2.push_back(20);
	vector<int> v3 ; v3.push_back(23); v3.push_back(30); v3.push_back(34); v3.push_back(50);
	test.push_back(v1) ; test.push_back(v2) ; test.push_back(v3) ; 

	cout << searchMatrix(test,3) << endl ;
}