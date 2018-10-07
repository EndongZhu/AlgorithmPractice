#include <iostream>

int search_closest(int num, int arr[], int len) {
    if(num <= arr[0])
        return arr[0] ;
    if(num >= arr[len-1])
        return arr[len-1] ;

    int lo = 0, hi = len-1 ;
    while(lo <= hi) {
        int mid = (lo+hi)/2 ;
        if(arr[mid] < num)
            lo = mid + 1 ;
        else if(arr[mid] > num)
            hi = mid - 1 ;
        else
            return arr[mid] ;
    }

    return abs(num-arr[lo]) < abs(num-arr[hi]) ? arr[lo] : arr[hi] ;
}

int main() {
    int houses[5] = {2,8,4,5,10};
    int stores[5] = {1,11,5,7,9};
    sort(stores, stores+5);
    int ans[5] ;
    for(int i = 0 ; i < 5 ; i++) {
        ans[i] = search_closest(houses[i], stores, 5) ;
    }
    for(int i = 0 ; i < 5 ; i++) {
        cout << ans[i] << " " ;
    }
}
