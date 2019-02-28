#include <vector>
#include <iostream>
using namespace std;

int quickSelect(vector<int>& arr, int low, int high, ink k) {
    int pivot = arr[low];
    int start = low;
    int end = high;
    while(low < high) {
        while(low < high && arr[high] > pivot) {
            --high;
        }
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot) {
            ++low;
        }
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    if (low == k) {
        return pivot;
    } else if (low > k) {
        return quickSelect(arr, start, l-1, k);
    } else {
        return quickSelect(arr, l+1, end, k-(l-start+1));
    }
}


int main() {
    int arr[] = {0,2,1,3,5,4,6};
    vector<int> v(arr, arr+7);
    cout << quickSelect(v, 0, v.size()-1, 3) << endl;
}
