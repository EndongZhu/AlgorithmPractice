#include <vector>
#include <iostream>
using namespace std ;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    for(int i = 0 ; i < n ; i++)
    {
        int num = nums2[i] ;
        for(int j = 0 ; j < m ; j++)
        {
            if(nums1[0] > num)
            {
                int pos = m ;
                while(pos)
                {
                    nums1[pos] = nums1[pos-1] ;
                    pos-- ;
                }
                nums1[0] = num ;
                break ;
            }
            else if(j == m-1)
            {
                if(nums1[j] <= num)
                    nums1[m] = num ;
                else
                {
                    nums1[m] = nums1[j] ;
                    nums1[j] = num ;
                }
                break ;
            }
            else if(nums1[j] <= num && nums1[j+1] > num)
            {
                int pos = m ;
                while(pos > j+1)
                {
                    nums1[pos] = nums1[pos-1] ;
                    pos-- ;
                }
                nums1[j+1] = num ;
                break ;
            }
        }
        if(m == 0)
        {
            nums1[0] = num ;
        }
        m++ ;
    }
}

int main()
{
    vector<int> nums1;
    nums1.push_back(4) ; nums1.push_back(5) ; nums1.push_back(6) ; nums1.push_back(0) ; nums1.push_back(0) ; nums1.push_back(0) ;
    vector<int> nums2;
    nums2.push_back(1) ; nums2.push_back(2) ; nums2.push_back(3) ;
    merge(nums1, 3, nums2, 3) ;
}
