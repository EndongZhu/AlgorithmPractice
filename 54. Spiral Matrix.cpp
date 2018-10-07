#include <iostream>
#include <vector>
using namespace std ;

vector<int> spiralOrder(vector< vector<int> >& matrix) 
{
    vector<int> ans ;
    int m = matrix.size() ;
    if(m == 0)
        return ans ;
    int n = matrix[0].size() ;

    int count = 0 ;
    int pos1 , pos2 = 0 ;
    while(count < m*n)
    {
        for(int j = pos2 ; j < n-pos2 ; j++)
        {
            ans.push_back(matrix[pos1][j]) ;
            count++ ;
        }
        if(count >= m*n)
            break ;
        pos2 = n-pos2-1 ;

        for(int i = pos1+1 ; i < m-pos1 ; i++)
        {
            ans.push_back(matrix[i][pos2]) ;
            count++ ;
        }
        if(count >= m*n)
            break ;
        pos1 = m-pos1-1 ;

        for(int j = pos2-1 ; j >= n-pos2-1 ; j--)
        {
            ans.push_back(matrix[pos1][j]) ;
            count++ ;
        }
        if(count >= m*n)
            break ;
        pos2 = n-pos2-1 ;

        for(int i = pos1-1 ; i > m-pos1-1 ; i--)
        {
            ans.push_back(matrix[i][pos2]) ;
            count++ ;
        }
        if(count >= m*n)
            break ;
        pos1 = m-pos1-1 ;

        pos1++ ;
        pos2++ ;
    } 
    return ans ;       
}

int main()
{
    vector<int> v1 ; v1.push_back(1) ; v1.push_back(2) ; v1.push_back(3) ; v1.push_back(4) ;
    vector<int> v2 ; v2.push_back(5) ; v2.push_back(6) ; v2.push_back(7) ; v2.push_back(8) ;
    vector<int> v3 ; v3.push_back(9) ; v3.push_back(10) ; v3.push_back(11) ; v3.push_back(12) ;
    vector< vector<int> > test ;
    test.push_back(v1) ;
    test.push_back(v2) ;
    test.push_back(v3) ;

    vector<int> res = spiralOrder(test) ;
    cout << res[0] << res[1] << res[2] << res[3] << res[4] << res[5] << res[6] << res[7] << res[8] << res[9] << res[10] << res[11] << endl ;
}
