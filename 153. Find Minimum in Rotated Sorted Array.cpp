int findMin(vector<int>& nums) {
    int n = nums.size() ;
    int left = 0 ;
    int right = n-1 ;
    while(left < right) {
        int mid = (left+right+1)/2 ;
        if(nums[mid] > nums[right]) {
            left = mid ;
        }
        else {
            right = mid ;
        }
    }
    return nums[left] ;
}
