vector<vector<int>> threeSum(vector<int>& nums) {
    nums.sort() ;
    vector<vector<int>> ans ;
    if(nums.size() < 3)
        return ans ;
    for(int i = 0; i < nums.size()-2; i++) {
        int left = i+1 ;
        int right = nums.size()-1 ;
        while(left < right) {
            if(nums[left]+nums[right]+nums[i] == 0) {
                vector<int> v ;
                v.push_back(nums[i]) ;
                v.push_back(nums[left]) ;
                v.push_back(nums[right]) ;
                ans.push_back(v) ;
                while(nums[left] == v[1])
                    left++ ;
                while(nums[right] == v[2])
                    right-- ;
            }
            else if(nums[left]+nums[right]+nums[i] < 0)
                left++ ;
            else
                right++ ;
        }
    }
    return ans ;
}
